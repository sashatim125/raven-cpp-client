#include "pch.h"
#include "DocumentStoreHolder.h"

namespace demo
{
	void DocumentStoreHolder::configureDocumentStore()
	{
		//Here you can add all kinds of configurations
		//as necessary, such as conventions, using certificates etc.

		_store->initialize();
	}

	DocumentStoreHolder::DocumentStoreHolder(const std::string& url, const std::string& databaseName)
		: _store(ravendb::client::documents::DocumentStore::create(url, databaseName))
	{
		configureDocumentStore();
	}

	DocumentStoreHolder::DocumentStoreHolder(const std::vector<std::string>& urls, const std::string& databaseName)
		: _store(ravendb::client::documents::DocumentStore::create(urls, databaseName))
	{
		configureDocumentStore();
	}

	std::shared_ptr<ravendb::client::documents::IDocumentStore> DocumentStoreHolder::getStore() const
	{
		return _store;
	}

	void DocumentStoreHolder::close()
	{
		std::static_pointer_cast<ravendb::client::documents::DocumentStore>(_store)->close();
	}
}
