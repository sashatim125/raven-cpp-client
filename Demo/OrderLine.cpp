#include "pch.h"
#include "OrderLine.h"

namespace demo::entities
{
	//Using the provided 'ravendb::client::impl::utils::json_utils::set_val_to_json' and
	//'ravendb::client::impl::utils::json_utils::get_val_from_json' utilities
	//is the most convenient way to make the serialization/deserialization.
	void to_json(nlohmann::json& j, const OrderLine& ol)
	{
		using ravendb::client::impl::utils::json_utils::set_val_to_json;

		set_val_to_json(j, "Product", ol.Product);
		set_val_to_json(j, "ProductName", ol.ProductName);
		set_val_to_json(j, "Quantity", ol.Quantity);
	}

	void from_json(const nlohmann::json& j, OrderLine& ol)
	{
		using ravendb::client::impl::utils::json_utils::get_val_from_json;

		get_val_from_json(j, "Product", ol.Product);
		get_val_from_json(j, "ProductName", ol.ProductName);
		get_val_from_json(j, "Quantity", ol.Quantity);
	}
}
