#pragma once
#include "raven_cpp_client.h"

namespace demo::entities
{
	//Each class/struct to be stored in the RavenDb database must be accompanied
	//with appropriate serializer/deserializer with the specific signature.
	struct Product
	{
		std::string ID{};
		std::string Name{};
		std::string Supplier{};
		std::string Category{};
		uint64_t QuantityPerUnit{};
		double PricePerUnit{};
		uint64_t UnitsInStock{};
		uint64_t UnitsOnOrder{};
		bool Discontinued{};
		int64_t ReorderLevel{};
	};

	void to_json(nlohmann::json& j, const Product& p);

	void from_json(const nlohmann::json& j, Product& p);
}
