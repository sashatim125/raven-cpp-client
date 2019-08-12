#pragma once
#include "raven_cpp_client.h"
#include "Supplier.h"
#include "Category.h"
#include "Product.h"
#include "Order.h"
#include "OrderLine.h"

namespace demo
{
	inline void createRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto supplier = std::make_shared<Supplier>();
		supplier->Name = "Hibernating Rhinos";
		supplier->Phone = "(+972)52-5486969";

		auto category = std::make_shared<Category>();
		category->Name = "NoSQL Databases";
		category->Description = "Non-relational databases";

		auto product = std::make_shared<demo::Product>();
		product->Name = "RavenDB";

		auto session = store->open_session();

		session.store(supplier);
		session.store(category);

		product->Supplier = supplier->ID;
		product->Category = category->ID;

		session.store(product);

		session.save_changes();
	}


	inline void loadRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& productId)
	{
		auto session = store->open_session();

		auto product = session.include("supplier").load<Product>(productId);

		auto supplier = session.load<Supplier>(product->Supplier);

		product->PricePerUnit = 12;
		supplier->Phone = "(+972)52-5486969";

		session.save_changes();
	}

	inline void queryRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& productId)
	{
		auto session = store->open_session();

		auto shippedOrders = session.query<Order>()
			->include("lines.product")
			->where_not_equals("shippedAt", nullptr)
			->to_list();

		for(const auto& shippedOrder : shippedOrders)
		{
			auto productIds = std::vector<std::string>{};
			productIds.reserve(shippedOrders.size());
			std::transform(shippedOrder->Lines.cbegin(), shippedOrder->Lines.cend(), std::back_inserter(productIds), 
				[](const auto& line){return line.Product;});

			for(decltype(productIds)::size_type i = 0; i < productIds.size(); ++i)
			{
				auto product = session.load<Product>(productIds.at(i));
				product->UnitsOnOrder += shippedOrder->Lines.at(i).Quantity;
			}
		}
		session.save_changes();
	}

	class Products_ByCategoryName : public ravendb::client::documents::indexes::AbstractIndexCreationTask
	{
	public:
		struct Result
		{
			std::string CategoryName;
		};

	public:
		~Products_ByCategoryName() override = default;
		Products_ByCategoryName()
		{
			SET_DEFAULT_INDEX_NAME();

			map = R"(
			docs.Products.Select(product => new
			{
				CategoryName = (this.LoadDocument(product.Category, "Categories")).Name
			}))";
		}
	};

	inline void indexRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& categoryName)
	{
		Products_ByCategoryName().execute(store);

		auto session = store->open_session();

		auto res = session.query<Product, Products_ByCategoryName>()
			->where_equals("CategoryName", categoryName)
			->to_list();
	}
}
