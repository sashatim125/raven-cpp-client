#include "pch.h"
#include <iostream>

#include "raven_cpp_client.h"
#include "DocumentStoreHolder.h"
#include "Category.h"
#include "Company.h"
#include "Employee.h"
#include "Order.h"
#include "Product.h"
#include "Supplier.h"

#include "advanced.h"
#include "basics.h"
#include "queries.h"
#include "related_documents.h"
#include "store_attachment.h"

//The 'id' field of the document on most cases should NOT be (de)serialized.
//Rather the user is encouraged to use the REGISTER_ID_PROPERTY_FOR(TYPE, ID) macro
//in the start of his program to let the session(s) to interact with that field
//(entering appropriate value upon the document storage
//or retrieving it for the custom document id usage).
void registerIdProperty()
{
	REGISTER_ID_PROPERTY_FOR(demo::entities::Category,	ID);
	REGISTER_ID_PROPERTY_FOR(demo::entities::Company,	ID);
	REGISTER_ID_PROPERTY_FOR(demo::entities::Employee,	ID);
	REGISTER_ID_PROPERTY_FOR(demo::entities::Order,		ID);
	REGISTER_ID_PROPERTY_FOR(demo::entities::Product,	ID);
	REGISTER_ID_PROPERTY_FOR(demo::entities::Supplier,	ID);
}

int main()
{
    std::cout << "Hello RavenDB!\n";

	registerIdProperty();

	auto storeHolder = demo::DocumentStoreHolder("http://localhost:8080", "YourDatabaseName");

}

