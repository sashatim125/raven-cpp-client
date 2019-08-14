#pragma once
#include "raven_cpp_client.h"

namespace demo::entities
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct Category
	{
		std::string ID{};
		std::string Name{};
		std::string Description{};
	};

	void to_json(nlohmann::json& j, const Category& c);

	void from_json(const nlohmann::json& j, Category& c);
}
