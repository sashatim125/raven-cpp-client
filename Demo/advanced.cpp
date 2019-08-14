#include "pch.h"
#include "advanced.h"

namespace demo
{
	auto createDatabase(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& databaseName)
	{
		auto databaseRecord = ravendb::client::serverwide::DatabaseRecord(databaseName);

		try
		{
			store->maintenance()->server()->send(
				ravendb::client::serverwide::operations::CreateDatabaseOperation(std::move(databaseRecord)));
		}
		catch (const ravendb::client::exceptions::ConcurrencyException& ce)
		{
			// Database already exists
		}
	}
}
