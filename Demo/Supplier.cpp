#include "pch.h"
#include "Supplier.h"

namespace demo
{
	//Using the provided 'ravendb::client::impl::utils::json_utils::set_val_to_json' and
	//'ravendb::client::impl::utils::json_utils::get_val_from_json' utilities
	//is the most convenient way to make the serialization/deserialization.
	void to_json(nlohmann::json& j, const Supplier& s)
	{
		using ravendb::client::impl::utils::json_utils::set_val_to_json;

		set_val_to_json(j, "Name", s.Name);
		set_val_to_json(j, "Phone", s.Phone);
	}

	void from_json(const nlohmann::json& j, Supplier& s)
	{
		using ravendb::client::impl::utils::json_utils::get_val_from_json;

		get_val_from_json(j, "Name", s.Name);
		get_val_from_json(j, "Phone", s.Phone);
	}
}
