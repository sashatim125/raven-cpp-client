#pragma once
#include "raven_cpp_client.h"
#include "OrderLine.h"

namespace demo
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct Order
	{
		std::string ID{};
		std::string Company{};
		std::optional<ravendb::client::impl::DateTimeOffset> ShippedAt{};
		std::vector<OrderLine> Lines{};
	};

	void to_json(nlohmann::json& j, const Order& o);

	void from_json(const nlohmann::json& j, Order& o);
}
