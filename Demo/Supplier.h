#pragma once
#include "raven_cpp_client.h"

namespace demo
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct Supplier
	{
		std::string ID{};
		std::string Name{};
		std::string Phone{};
	};

	void to_json(nlohmann::json& j, const Supplier& s);

	void from_json(const nlohmann::json& j, Supplier& s);
}
