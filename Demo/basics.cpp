#include "pch.h"
#include "basics.h"
#include "Company.h"

namespace demo
{
	void usingSession(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
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

	void createDocument(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		//It is an obligatory to create an entity and pass it to the session as 'std::shared_ptr'.
		//This format is essential for the entity to track the document changes.
		auto newCompany = std::make_shared<demo::entities::Company>();

		newCompany->Name = "Hibernating Rhinos";
		newCompany->Phone = "(0972)52-5486969";

		newCompany->Contact.Name = "Yossy Cohn";
		newCompany->Contact.Title = "support";

		{
			auto session = store->open_session();
			//all session.store() overloads accepts a custom to_json serializer.
			session.store(newCompany);
			session.save_changes();
		}

		//The session takes care of generating the document identifier automatically.
		//The new stored entity ID is now available and can be used.
		//This is available with using the REGISTER_ID_PROPERTY_FOR(TYPE, ID) macro.
		std::cout << "The new document with the id " << newCompany->ID << " was created and stored." << std::endl;
	}

	void editDocument(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& documentId)
	{
		auto session = store->open_session();

		//The loaded document is returned as 'std::shared_ptr' to enable the session to track its changes.
		//Empty std::shared_ptr is returned if there is no document with the provided id.
		//Also all session.load overloads support the user defined deserializer
		//for immediate usage and the user defined serializer for sending the document to the server
		auto company = session.load<entities::Company>(documentId);

		if (!company)
		{
			throw std::runtime_error("No document with the id : " + documentId);
		}

		company->Contact.Title = "senior support";

		session.save_changes();
	}

	void deleteDocument(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& documentId)
	{
		auto session = store->open_session();

		session.delete_document(documentId);

		session.save_changes();
	}
}
