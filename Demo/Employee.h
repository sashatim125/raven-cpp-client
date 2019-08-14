#pragma once
#include "raven_cpp_client.h"
#include "Address.h"

namespace demo::entities
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct Employee
	{
		//The 'id' field on most cases should NOT be (de)serialized.
		//Rather the user is encouraged to use the REGISTER_ID_PROPERTY_FOR(TYPE, ID) macro
		//in the start of his program to let the session(s) to interact with that field
		//(entering appropriate value upon the document storage
		//or retrieving it for the custom document id usage).
		std::string ID{};
		std::string LastName{};
		std::string FirstName{};
		std::string Title{};
		ravendb::client::impl::DateTimeOffset Birthday{};
		std::string HomePhone{};
		std::string Extension{};
		ravendb::client::impl::DateTimeOffset HiredAt{};
		std::string ReportsTo{};
		Address Address{};
		std::vector<std::string> Territories{};
	};

	void to_json(nlohmann::json& j, const Employee& e);

	void from_json(const nlohmann::json& j, Employee& e);
}
