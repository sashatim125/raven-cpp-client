#include "pch.h"
#include "Address.h"

namespace demo::entities
{
	//Using the provided 'ravendb::client::impl::utils::json_utils::set_val_to_json' and
	//'ravendb::client::impl::utils::json_utils::get_val_from_json' utilities
	//is the most convenient way to make the serialization/deserialization.
	void to_json(nlohmann::json& j, const Address& a)
	{
		using ravendb::client::impl::utils::json_utils::set_val_to_json;

		set_val_to_json(j, "Line1", a.Line1);
		set_val_to_json(j, "Line2", a.Line2);
		set_val_to_json(j, "City", a.City);
		set_val_to_json(j, "Country", a.Country);
	}

	void from_json(const nlohmann::json& j, Address& a)
	{
		using ravendb::client::impl::utils::json_utils::get_val_from_json;

		get_val_from_json(j, "Line1", a.Line1);
		get_val_from_json(j, "Line2", a.Line2);
		get_val_from_json(j, "City", a.City);
		get_val_from_json(j, "Country", a.Country);
	}
}
