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

	auto projectingIndividualFields(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

	auto projectingUsingFunctions(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

	auto sortingQueryResults(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		uint64_t numberOfUnits);

	auto pagingQueryResults(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		int32_t resultsToSkip,
		int32_t resultsToTake,
		std::optional<int32_t>& totalResults);
}
