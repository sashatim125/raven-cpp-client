#include "pch.h"
#include "EmployeeDetails.h"

namespace demo::misc
{
	//Using the provided 'ravendb::client::impl::utils::json_utils::set_val_to_json' and
	//'ravendb::client::impl::utils::json_utils::get_val_from_json' utilities
	//is the most convenient way to make the serialization/deserialization.

	void to_json(nlohmann::json& j, const EmployeeDetails& ed)
	{
		using ravendb::client::impl::utils::json_utils::set_val_to_json;

		set_val_to_json(j, "LastName", ed.LastName);
		set_val_to_json(j, "FirstName", ed.FirstName);
		set_val_to_json(j, "Title", ed.Title);
		set_val_to_json(j, "HiredAt", ed.HiredAt);
	}

	void from_json(const nlohmann::json& j, EmployeeDetails& ed)
	{
		using ravendb::client::impl::utils::json_utils::get_val_from_json;

		get_val_from_json(j, "LastName", ed.LastName);
		get_val_from_json(j, "FirstName", ed.FirstName);
		get_val_from_json(j, "Title", ed.Title);
		get_val_from_json(j, "HiredAt", ed.HiredAt);
	}
}
