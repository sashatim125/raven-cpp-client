#pragma once
#include <unordered_map>
#include <string>
#include "json.hpp"

namespace  ravendb::client
{
	using Parameters = std::unordered_map<std::string, nlohmann::json>;
}
