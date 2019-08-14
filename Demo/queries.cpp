#include "pch.h"
#include "queries.h"
#include "Employee.h"
#include "EmployeeDetails.h"
#include "Company.h"

namespace demo
{
	auto simpleQuery(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto session = store->open_session();

		//All queries are implemented as the std::shared_ptr's.
		auto queryDefinition = session.query<entities::Employee>();
		// Define actions such as:

		// Filter documents by documents fields
		// Filter documents by text criteria 
		// Include related documents
		// Get the query stats
		// Sort results 
		// Customise the returned entity fields (Projections)
		// Control results paging  

		//The query result is an std::vector of the query results as std::shared_ptr.
		auto queryResults = queryDefinition->to_list();

		return queryResults;
	}

	auto queryExample(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto session = store->open_session();

		auto queryStatistics = std::shared_ptr<ravendb::client::documents::session::QueryStatistics>();

		/*auto fields = std::vector<std::string>{
			"FirstName",
			"LastName",
			"Title",
			"HiredAt" };*/

		auto query = session.query<entities::Employee>()
	        ->open_subclause()
	        ->where_equals("FirstName", "Steven")
	        ->or_else()
	        ->where_equals("Title", "Sales Representative")
	        ->close_subclause()
	        ->include("ReportsTo")
	        ->statistics(queryStatistics)
	        ->order_by_descending("HiredAt")
	        /*_1_*/->select_fields<misc::EmployeeDetails>()
	        /*_2_*/ //->select_fields<misc::EmployeeDetails>(fields)
	        ->take(5);

		auto queryResults = query->to_list();

		//Explanations : 
		//	_1_: using the fields names list retrieving method(by serializing empty object and getting the names from JSON)
		//		(the result is cached(!))
		//	_2_: providing custom fields names list

		return queryResults;
	}

	auto fullCollectionQuery(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto session = store->open_session();

		auto fullCollectionQuery = session.query<entities::Company>();

		auto collectionResults = fullCollectionQuery->to_list();

		return collectionResults;
	}

	auto queryByDocumentId(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& employeeDocumentId)
	{
		auto session = store->open_session();

		auto queryByDocumentID = session.query<entities::Employee>()
			//use "id()" as the 'field_name' argument for querying by the document's id
			->where_equals("id()", employeeDocumentId);

		auto employee = queryByDocumentID->first_or_default();

		return employee;
	}

	auto filteringResultsBasics(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto session = store->open_session();

		auto filteredQuery = session.query<entities::Employee>()
		                            ->where_equals("FirstName", "Anne");

		auto filteredEmployees = filteredQuery->to_list();

		return filteredEmployees;
	}

	auto filteringResultsMultipleConditions(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& country)
	{
		auto session = store->open_session();

		auto query = session.query<entities::Employee>()
	        ->where_in("FirstName", std::vector<std::string>{"Anne", "John"})
	        ->or_else()
	        ->open_subclause()
	        ->where_equals("Address.Country", country)
	        ->and_also()
	        ->where_greater_than("Territories.Count", 2)
	        ->and_also()
	        ->where_starts_with("Title", "Sales")
	        ->close_subclause();

		auto filteredEmployees = query->to_list();

		return filteredEmployees;
	}
}
