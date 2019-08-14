#pragma once
#include "raven_cpp_client.h"

namespace demo
{

	//The Session, which is derived from the Document Store,
	//is the primary way your client code interacts with your RavenDB databases.
	//The Session is a unit of work that represents a single business transaction against a particular database,
	//managing change tracking for all the entities that it has either loaded or stored.

	void usingSession(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

	void createDocument(std::shared_ptr<ravendb::client::documents::IDocumentStore> store);

	void editDocument(std::shared_ptr<ravendb::client::documents::IDocumentStore> store, const std::string& documentId);

	void deleteDocument(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& documentId);
}
