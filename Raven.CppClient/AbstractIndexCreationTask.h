#pragma once
#include "AbstractGenericIndexCreationTask.h"

namespace ravendb::client::documents::indexes
{
	class AbstractIndexCreationTask : public AbstractGenericIndexCreationTask
	{
	public:
		~AbstractIndexCreationTask() override;

		IndexDefinition create_index_definition() override;

		bool is_map_reduce() const override;
	};
}
