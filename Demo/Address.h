#pragma once
#include "raven_cpp_client.h"

namespace demo::entities
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct Address
	{
		std::string Line1{};
		std::optional<std::string> Line2{};
		std::string City{};
		std::string Country{};
	};

	void to_json(nlohmann::json& j, const Address& a);

	void from_json(const nlohmann::json& j, Address& a);
}
