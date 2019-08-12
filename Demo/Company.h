#pragma once
#include "raven_cpp_client.h"
#include "Contact.h"

namespace demo
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct Company
	{
		//The 'id' field on most cases should NOT be (de)serialized.
		//Rather the user is encouraged to use the REGISTER_ID_PROPERTY_FOR(TYPE, ID) macro
		//in the start of his program to let the session(s) to interact with that field
		//(entering appropriate value upon the document storage
		//or retrieving it for the custom document id usage).
		std::string ID{};
		std::string Name{};
		std::string Phone{};

		Contact Contact{};
	};

	void to_json(nlohmann::json& j, const Company& c);

	void from_json(const nlohmann::json& j, Company& c);
}
