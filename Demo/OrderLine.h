#pragma once
#include "raven_cpp_client.h"

namespace demo
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct OrderLine
	{
		std::string Product{};
		std::string ProductName{};
		uint64_t Quantity{};
	};

	void to_json(nlohmann::json& j, const OrderLine& ol);

	void from_json(const nlohmann::json& j, OrderLine& ol);
}
