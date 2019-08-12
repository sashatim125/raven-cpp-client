#pragma once
#include "raven_cpp_client.h"

namespace demo
{
	//The Document Store is the main Client API object that establishes the communication between your client application
	//and the RavenDB cluster.
	//It is the single access point to a particular cluster,
	//exposing methods to perform operations against the associated server instances,
	//holding the configuration, topology, cache and any customizations that you might have applied.
	//The Document Store is thread safe.
	//A single instance of a Document Store should be used per the lifetime of the application.
	class DocumentStoreHolder
	{
	private:
		const std::shared_ptr<ravendb::client::documents::IDocumentStore> _store;

	private:
		void configureDocumentStore();

	public:
		DocumentStoreHolder(const std::string& url, const std::string& databaseName);
		DocumentStoreHolder(const std::vector<std::string>& urls, const std::string& databaseName);

		std::shared_ptr<ravendb::client::documents::IDocumentStore> getStore() const;

		//Upon its close, the DocumentStore performs some important operations, like
		//sending to the server the unused HiLo ranges.
		//Those operations are performed by the 'close()' method, which may throw(!).
		//This method, if not called explicitly, is called by the DTOR, but all exceptions
		//are silently cached and NOT PROCESSED.
		//So for processing any possible errors upon the DocumentStore closing,
		//it is recommended to use the provided 'close()' method explicitly.
		void close();
	};
}
