#pragma once
#include "raven_cpp_client.h"
#include "Employee.h"

namespace demo
{
	class Employees_ByLastName : public ravendb::client::documents::indexes::AbstractIndexCreationTask
	{
	public:
		~Employees_ByLastName() override = default;
		Employees_ByLastName()
		{
			SET_DEFAULT_INDEX_NAME();

			map = "from e in docs.Employees select new { e.LastName }";
		}
	};

	inline auto staticIndexesOverview(std::shared_ptr<ravendb::client::documents::IDocumentStore> store)
	{
		Employees_ByLastName().execute(store);
		//or store->execute_index(std::make_shared<Employees_ByLastName>()); 

		auto session = store->open_session();

		auto queryOnIndex = session.query<entities::Employee, Employees_ByLastName>()
			->where_equals("LastName", "SomeName");

		auto queryResults = queryOnIndex->to_list();

		return queryResults;
	}

}
