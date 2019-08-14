#include "pch.h"
#include "related_documents.h"
#include "Supplier.h"
#include "Category.h"
#include "Product.h"
#include "Order.h"

namespace demo
{
	void createRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto supplier = std::make_shared<entities::Supplier>();
		supplier->Name = "Hibernating Rhinos";
		supplier->Phone = "(+972)52-5486969";

		auto category = std::make_shared<entities::Category>();
		category->Name = "NoSQL Databases";
		category->Description = "Non-relational databases";

		auto product = std::make_shared<entities::Product>();
		product->Name = "RavenDB";

		auto session = store->open_session();

		session.store(supplier);
		session.store(category);

		product->Supplier = supplier->ID;
		product->Category = category->ID;

		session.store(product);

		session.save_changes();
	}

	void loadRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& productId)
	{
		auto session = store->open_session();

		auto product = session.include("Supplier").load<entities::Product>(productId);

		//The following command DOES NOT make a request to the server since the asked document is
		//already "loaded" into the session.
		auto supplier = session.load<entities::Supplier>(product->Supplier);

		product->PricePerUnit = 12;
		supplier->Phone = "(+972)52-5486969";

		session.save_changes();
	}

	void queryRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto session = store->open_session();

		auto shippedOrders = session.query<entities::Order>()
	        ->include("lines.product")
			//nullptr is used as an alias for the 'null' json field value
	        ->where_not_equals("shippedAt", nullptr)
	        ->to_list();

		for (const auto& shippedOrder : shippedOrders)
		{
			auto productIds = std::vector<std::string>{};
			productIds.reserve(shippedOrders.size());
			std::transform(shippedOrder->Lines.cbegin(), shippedOrder->Lines.cend(), std::back_inserter(productIds),
				[](const auto& line) { return line.Product; });

			for (decltype(productIds)::size_type i = 0; i < productIds.size(); ++i)
			{
				auto product = session.load<entities::Product>(productIds[i]);
				product->UnitsOnOrder += shippedOrder->Lines.at(i).Quantity;
			}
		}
		session.save_changes();
	}

	auto indexRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& categoryName)
	{
		Products_ByCategoryName().execute(store);

		auto session = store->open_session();

		auto res = session.query<entities::Product, Products_ByCategoryName>()
	      ->where_equals("CategoryName", categoryName)
	      ->to_list();

		return res;
	}
}
