#include "pch.h"
#include "Order.h"

namespace demo
{
	//Using the provided 'ravendb::client::impl::utils::json_utils::set_val_to_json' and
	//'ravendb::client::impl::utils::json_utils::get_val_from_json' utilities
	//is the most convenient way to make the serialization/deserialization.
	void to_json(nlohmann::json& j, const Order& o)
	{
		using ravendb::client::impl::utils::json_utils::set_val_to_json;

		set_val_to_json(j, "Company", o.Company);
		set_val_to_json(j, "ShippedAt", o.ShippedAt);
		set_val_to_json(j, "Lines", o.Lines);
	}

	void from_json(const nlohmann::json& j, Order& o)
	{
		using ravendb::client::impl::utils::json_utils::get_val_from_json;

		get_val_from_json(j, "Company", o.Company);
		get_val_from_json(j, "ShippedAt", o.ShippedAt);
		get_val_from_json(j, "Lines", o.Lines);
	}
}
