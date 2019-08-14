#pragma once
#include "raven_cpp_client.h"

namespace demo
{
	auto simpleQuery(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

	auto queryExample(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

	auto fullCollectionQuery(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

	auto queryByDocumentId(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& employeeDocumentId);

	auto filteringResultsBasics(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

	auto filteringResultsMultipleConditions(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& country);
}
