#include "pch.h"
#include "Product.h"

namespace demo
{
	//Using the provided 'ravendb::client::impl::utils::json_utils::set_val_to_json' and
	//'ravendb::client::impl::utils::json_utils::get_val_from_json' utilities
	//is the most convenient way to make the serialization/deserialization.
	void to_json(nlohmann::json& j, const Product& p)
	{
		using ravendb::client::impl::utils::json_utils::set_val_to_json;
		
		set_val_to_json(j, "Name", p.Name);
		set_val_to_json(j, "Supplier", p.Supplier);
		set_val_to_json(j, "Category", p.Category);
		set_val_to_json(j, "PricePerUnit", p.PricePerUnit);
		set_val_to_json(j, "UnitsOnOrder", p.UnitsOnOrder);
	}

	void from_json(const nlohmann::json& j, Product& p)
	{
		using ravendb::client::impl::utils::json_utils::get_val_from_json;

		get_val_from_json(j, "Name", p.Name);
		get_val_from_json(j, "Supplier", p.Supplier);
		get_val_from_json(j, "Category", p.Category);
		get_val_from_json(j, "PricePerUnit", p.PricePerUnit);
		get_val_from_json(j, "UnitsOnOrder", p.UnitsOnOrder);
	}
}
