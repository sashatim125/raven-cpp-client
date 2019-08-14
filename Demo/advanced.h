#pragma once
#include "raven_cpp_client.h"

namespace demo
{
	auto createDatabase(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& databaseName);
}
