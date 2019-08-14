#pragma once
#include "raven_cpp_client.h"

namespace demo
{
	void createRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

	void loadRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& productId);

	void queryRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

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

	auto indexRelatedDocuments(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& categoryName);
}
