#include "pch.h"
#include "CompanyDetails.h"

namespace demo::misc
{
	//Using the provided 'ravendb::client::impl::utils::json_utils::set_val_to_json' and
	//'ravendb::client::impl::utils::json_utils::get_val_from_json' utilities
	//is the most convenient way to make the serialization/deserialization.

	void to_json(nlohmann::json& j, const CompanyDetails& cd)
	{
		using ravendb::client::impl::utils::json_utils::set_val_to_json;

		set_val_to_json(j, "CompanyName", cd.CompanyName);
		set_val_to_json(j, "City", cd.City);
		set_val_to_json(j, "Country", cd.Country);
	}

	void from_json(const nlohmann::json& j, CompanyDetails& cd)
	{
		using ravendb::client::impl::utils::json_utils::get_val_from_json;

		get_val_from_json(j, "CompanyName", cd.CompanyName);
		get_val_from_json(j, "City", cd.City);
		get_val_from_json(j, "Country", cd.Country);
	}
}