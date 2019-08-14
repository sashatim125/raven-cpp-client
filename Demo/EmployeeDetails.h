#pragma once
#include "raven_cpp_client.h"

namespace demo::misc
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct EmployeeDetails
	{
		std::string FirstName{};
		std::string LastName{};
		std::string Title{};
		ravendb::client::impl::DateTimeOffset HiredAt{};
	};

	void to_json(nlohmann::json& j, const EmployeeDetails& ed);

	void from_json(const nlohmann::json& j, EmployeeDetails& ed);
}
