#include "pch.h"
#include "queries.h"
#include "Employee.h"
#include "EmployeeDetails.h"
#include "Company.h"
#include "CompanyDetails.h"
#include "Product.h"

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

	auto projectingIndividualFields(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto session = store->open_session();

		auto projectedQuery = session.query<entities::Company>()
			->select_fields<misc::CompanyDetails>({
			{ "Name", "Address.City", "Address.Country" },//the document's fields
			{ "CompanyName", "City", "Country" } });//the projection fields

		auto projectedResults = projectedQuery->to_list();

		return projectedResults;
	}

	auto projectingUsingFunctions(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		auto session = store->open_session();

		auto rawQueryString = R"(
			declare function output(employee) {
			var formatName = function(employee) { return "Full Name: " + employee.FirstName + " " + employee.LastName; };
			var formatTitle = function(employee) { return "Title: " + employee.Title };
			return { FullName: formatName(employee), Title : formatTitle(employee) };
			}
			from Employees as employee select output(employee))";

		auto query = session.advanced().raw_query<misc::EmployeeDetails>(rawQueryString);

		auto projectedResults = query->to_list();

		return projectedResults;
	}

	auto sortingQueryResults(std::shared_ptr<ravendb::client::documents::IDocumentStore> store, uint64_t numberOfUnits)
	{
		auto session = store->open_session();

		auto sortedProducts = session.query<entities::Product>()
			->where_greater_than("UnitsInStock", numberOfUnits)
			->order_by_descending("UnitsInStock", ravendb::client::documents::session::OrderingType::LONG)
			->order_by("Name", ravendb::client::documents::session::OrderingType::ALPHA_NUMERIC)
			->to_list();

		return sortedProducts;
	}

	auto pagingQueryResults(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		int32_t resultsToSkip,
		int32_t resultsToTake,
		std::optional<int32_t>& totalResults)
	{
		auto session = store->open_session();

		auto queryStatistics = std::shared_ptr<ravendb::client::documents::session::QueryStatistics>{};

		auto pagedResults = session.query<entities::Company>()
			->statistics(queryStatistics)
			->skip(resultsToSkip)
			->take(resultsToTake)
			->to_list();

		totalResults.emplace(queryStatistics->total_results);

		return pagedResults;
	}
}
