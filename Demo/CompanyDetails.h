#pragma once
#include "raven_cpp_client.h"

namespace demo::misc
{
	struct CompanyDetails
	{
		std::string CompanyName{};
		std::string City{};
		std::string Country{};

	};

	void to_json(nlohmann::json& j, const CompanyDetails& cd);

	void from_json(const nlohmann::json& j, CompanyDetails& cd);
}
