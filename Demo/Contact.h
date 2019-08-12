#pragma once
#include "raven_cpp_client.h"

namespace demo
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct Contact
	{
		std::string Name{};
		std::string Title{};
	};

	void to_json(nlohmann::json& j, const Contact& c);

	void from_json(const nlohmann::json& j, Contact& c);
}
