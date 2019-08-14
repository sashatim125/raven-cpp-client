#include "pch.h"
#include "Employee.h"

namespace demo::entities
{
	//Using the provided 'ravendb::client::impl::utils::json_utils::set_val_to_json' and
	//'ravendb::client::impl::utils::json_utils::get_val_from_json' utilities
	//is the most convenient way to make the serialization/deserialization.

	void to_json(nlohmann::json& j, const Employee& e)
	{
		using ravendb::client::impl::utils::json_utils::set_val_to_json;

		set_val_to_json(j, "LastName", e.LastName);
		set_val_to_json(j, "FirstName", e.FirstName);
		set_val_to_json(j, "Title", e.Title);
		set_val_to_json(j, "Birthday", e.Birthday);
		set_val_to_json(j, "HomePhone", e.HomePhone);
		set_val_to_json(j, "Extension", e.Extension);
		set_val_to_json(j, "HiredAt", e.HiredAt);
		set_val_to_json(j, "ReportsTo", e.ReportsTo);
		set_val_to_json(j, "Address", e.Address);
		set_val_to_json(j, "ReportsTo", e.ReportsTo);
	}

	void from_json(const nlohmann::json& j, Employee& e)
	{
		using ravendb::client::impl::utils::json_utils::get_val_from_json;

		get_val_from_json(j, "LastName", e.LastName);
		get_val_from_json(j, "FirstName", e.FirstName);
		get_val_from_json(j, "Title", e.Title);
		get_val_from_json(j, "Birthday", e.Birthday);
		get_val_from_json(j, "HomePhone", e.HomePhone);
		get_val_from_json(j, "Extension", e.Extension);
		get_val_from_json(j, "HiredAt", e.HiredAt);
		get_val_from_json(j, "ReportsTo", e.ReportsTo);
		get_val_from_json(j, "Address", e.Address);
		get_val_from_json(j, "Territories", e.Territories);
	}
}
