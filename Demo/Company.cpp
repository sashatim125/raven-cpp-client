#include "pch.h"
#include "Company.h"

namespace demo
{
	//Using the provided 'ravendb::client::impl::utils::json_utils::set_val_to_json' and
	//'ravendb::client::impl::utils::json_utils::get_val_from_json' utilities
	//is the most convenient way to make the serialization/deserialization.

	void to_json(nlohmann::json& j, const Company& c)
	{
		using ravendb::client::impl::utils::json_utils::set_val_to_json;

		set_val_to_json(j, "Name", c.Name);
		set_val_to_json(j, "Phone", c.Phone);
		set_val_to_json(j, "Contact", c.Contact);
	}

	void from_json(const nlohmann::json& j, Company& c)
	{
		using ravendb::client::impl::utils::json_utils::get_val_from_json;

		get_val_from_json(j, "Name", c.Name);
		get_val_from_json(j, "Phone", c.Phone);
		get_val_from_json(j, "Contact", c.Contact);
	}
}
