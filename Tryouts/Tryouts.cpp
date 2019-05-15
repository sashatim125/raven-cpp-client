
#include "pch.h"
#include <curl/curl.h>
#include <thread>
#include "DocumentStore.h"
#include "DocumentSession.h"
#include "User.h"
#include "GetDatabaseTopologyCommand.h"
#include "EntityIdHelperUtil.h"
#include "GetNextOperationIdCommand.h"
#include "TasksExecutor.h"
#include "GetDatabaseNamesOperation.h"
#include "RavenException.h"

namespace
{
	//using fiddler + verbose
	void set_for_fiddler(CURL* curl)
	{
		curl_easy_setopt(curl, CURLOPT_PROXY, "127.0.0.1:8888");
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
	}

	void set_for_verbose(CURL* curl)
	{
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
	}
}

int main()
{
	using namespace ravendb::client;

	REGISTER_ID_PROPERTY_FOR(ravendb::client::tests::infrastructure::entities::User, id);

	//auto store = documents::DocumentStore::create();
	//store->set_urls({ "http://127.0.0.1:8080" });
	//store->set_before_perform(set_for_fiddler);
	//store->set_database("Test");
	//store->initialize();

	//{
	//	auto session = store->open_session();
	//	auto user = std::make_shared<tests::infrastructure::entities::User>();
	//	session.store(user);
	//	session.save_changes();
	//}

	//auto conventions = documents::conventions::DocumentConventions::create();
	//conventions->set_read_balance_behavior(http::ReadBalanceBehavior::FASTEST_NODE);
	//conventions->freeze();
	//auto executor = http::RequestExecutor::create({ "http://127.0.0.1:8080" }, "Test",
	//	{}, std::make_shared<impl::TasksScheduler>(std::make_shared<impl::TasksExecutor>(4)), 
	//	conventions, set_for_fiddler);

	//for (auto i = 0; i < 100; ++i)
	//{
	//	auto cmd = serverwide::operations::GetDatabaseNamesOperation(0, 20).get_command(conventions);
	//	executor->execute(*cmd);
	//	std::this_thread::sleep_for(std::chrono::seconds(10));
	//}

	try
	{
		throw exceptions::RavenException();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}