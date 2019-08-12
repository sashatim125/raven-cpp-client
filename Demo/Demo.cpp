// Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>

#include "raven_cpp_client.h"
#include "DocumentStoreHolder.h"
#include "basics.h"
#include "related_documents.h"

//The 'id' field on most cases should NOT be (de)serialized.
//Rather the user is encouraged to use the REGISTER_ID_PROPERTY_FOR(TYPE, ID) macro
//in the start of his program to let the session(s) to interact with that field
//(entering appropriate value upon the document storage
//or retrieving it for the custom document id usage).
inline void registerIdProperty()
{
	REGISTER_ID_PROPERTY_FOR(demo::Category	,	ID);
	REGISTER_ID_PROPERTY_FOR(demo::Company	,	ID);
	REGISTER_ID_PROPERTY_FOR(demo::Order	,	ID);
	REGISTER_ID_PROPERTY_FOR(demo::Product	,	ID);
	REGISTER_ID_PROPERTY_FOR(demo::Supplier	,	ID);
}

int main()
{
    std::cout << "Hello World!\n";

	auto storeHolder = demo::DocumentStoreHolder("http://localhost:8080", "YourDatabaseName");

	auto company1 = std::make_shared<demo::Company>();
	company1->Name = "abc";

	auto company2 = std::make_shared<demo::Company>();
	company1->Name = "abc";

	auto session = storeHolder.getStore()->open_session();
	session.store(company1);
	session.store(company2);

	auto changes = session.advanced().what_changed();

	int x = 5;

}

