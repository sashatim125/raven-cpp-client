#pragma once
#include "raven_cpp_client.h"
#include "Company.h"

namespace demo
{

	//The Session, which is derived from the Document Store,
	//is the primary way your client code interacts with your RavenDB databases.
	//The Session is a unit of work that represents a single business transaction against a particular database,
	//managing change tracking for all the entities that it has either loaded or stored.

	inline void usingSession(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto session = store->open_session();

		//   Run your business logic:
		//   
		//   Store documents
		//   Load and Modify documents
		//   Query indexes & collections 
		//   Delete documents
		//   .... etc.

		session.save_changes();
	}

	inline void createDocument(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		//It is an obligatory to create an entity and pass it to the session as 'std::shared_ptr'.
		//This format is essential for the entity to track the document changes.
		auto newCompany = std::make_shared<demo::Company>();

		newCompany->Name = "Hibernating Rhinos";
		newCompany->Phone = "(0972)52-5486969";

		newCompany->Contact.Name = "Yossy Cohn";
		newCompany->Contact.Title = "support";

		{
			auto session = store->open_session();
			session.store(newCompany);
			session.save_changes();
		}

		//The session takes care of generating the document identifier automatically.
		//The new stored entity ID is now available and can be used.
		//This is available with using the REGISTER_ID_PROPERTY_FOR(TYPE, ID) macro.
		std::cout << "The new document with the id " << newCompany->ID << " was created and stored." << std::endl;
	}

	inline void editDocument(std::shared_ptr<ravendb::client::documents::IDocumentStore> store, const std::string& documentId)
	{
		auto session = store->open_session();

		//The loaded document is returned as 'std::shared_ptr' to enable the session to track its changes.
		//Empty std::shared_ptr is returned if there is no document with the provided id.
		auto company = session.load<Company>(documentId);

		if(!company)
		{
			throw std::runtime_error("No document with the id : " + documentId);
		}

		company->Contact.Title = "senior support";

		session.save_changes();
	}

	inline void deleteDocument(std::shared_ptr<ravendb::client::documents::IDocumentStore> store, const std::string& documentId)
	{
		auto session = store->open_session();

		session.delete_document(documentId);

		session.save_changes();
	}
}
