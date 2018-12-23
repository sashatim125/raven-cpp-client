//
#include "pch.h"
#include <iostream>

#include "User.h"

#include "GetDocumentsCommand.h"
#include "PutDocumentCommand.h"
#include "RequestExecutor.h"
#include "GetDatabaseRecordOperation.h"
#include "CreateDatabaseOperation.h"

#include "GetDatabaseNamesOperation.h"
#include "DeleteDatabasesOperation.h"
#include "DeleteDocumentCommand.h"
#include "CreateSampleDataOperation.h"
#include "PutIndexesOperation.h"
#include "GetIndexOperation.h"
#include "GetIndexesOperation.h"
#include "QueryCommand.h"
#include "DateTimeOffset.h"
#include "IndexHasChangedOperation.h"
#include "DeleteIndexOperation.h"
#include "DisableIndexOperation.h"
#include "EnableIndexOperation.h"
#include "ResetIndexOperation.h"
#include "StartIndexOperation.h"
#include "StopIndexOperation.h"
#include "StopIndexingOperation.h"
#include "StartIndexingOperationh.h"
#include "GetIndexNamesOperation.h"
#include "GetIndexErrorsOperation.h"
#include "SetIndexesLockOperation.h"
#include "GetIndexesStatisticsOperation.h"
#include "GetIndexingStatusOperation.h"
#include "GetTermsOperation.h"
#include "SetIndexesPriorityOperation.h"
#include "CertificateDetails.h"
#include <fstream>


namespace
{
	std::shared_ptr<ravendb::client::impl::CertificateDetails> get_cert()
	{
		static std::shared_ptr<ravendb::client::impl::CertificateDetails> cert_det{};

		if(!cert_det)
		{
			cert_det = std::make_shared<ravendb::client::impl::CertificateDetails>();
			std::ifstream cert_file(R"(C:\work\PowerUser\PowerUser.crt)");
			std::ifstream key_file(R"(C:\work\PowerUser\PowerUser.key)");
			//std::ifstream cert_file(R"(c:\work\alexander-pc\alexander-pc.crt)");
			//std::ifstream key_file(R"(C:\work\alexander-pc\alexander-pc.key)");
			{
				std::stringstream stream;
				stream << cert_file.rdbuf();
				cert_det->certificate = stream.str();
			}
			{
				std::stringstream stream;
				key_file >> stream.rdbuf();
				cert_det->key = stream.str();
			}
			//cert_det->ca_path = "../ca-bundle.crt";
			cert_det->key_password = "PowerUser";
		}
		return cert_det;
	}

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

	//User user{ "Alexander","Timoshenko" };
	//nlohmann::json j = user;
	//std::string id{ "newID123" };
	//auto _executor = ravendb::client::http::RequestExecutor::create({ "http://127.0.0.1:8080" }, "TEST__DocumentCommandsTests", {},
	//	{ debug_curl_init, nullptr });
	//{
	//	documents::commands::PutDocumentCommand cmd(id, {}, j);
	//	_executor->execute(cmd);
	//}
	//{
	//	documents::commands::DeleteDocumentCommand cmd(id,"dssdf");
	//	_executor->execute(cmd);
	//}

	//auto exec = http::RequestExecutor::create({ "http://127.0.0.1:8080" }, {}, {}, set_for_fiddler);
	//serverwide::DatabaseRecord rec;
	//rec.database_name = "Test";
	//rec.topology.members.push_back("A");
	//serverwide::operations::CreateDatabaseCommand cmd(rec,1);
	//auto res1 = exec->execute(cmd);

	//for (auto& it : res1.topology.promotables_status)
	//{
	//	std::cout << static_cast<uint8_t>(it.second)<<" ";
	//}

	//auto test_suite_executor = http::RequestExecutor::create({ "http://127.0.0.1:8080" }, "Test", {}, set_for_fiddler);
	//tests::infrastructure::CreateSampleDataCommand cmd2;
	//test_suite_executor->execute(cmd2);


	//auto test_suite_executor = http::RequestExecutor::create({ "http://127.0.0.1:8080" }, "Test", {}, set_for_fiddler);
	//std::string id1(500,'a'), id2 = id1+"aaa", id3 = id2+"AAA";

	//documents::commands::GetDocumentsCommand cmd({id1,id2,id3}, {}, true);
	//test_suite_executor->execute(cmd);

	//serverwide::operations::GetDatabaseRecordCommand cmd2("test");

	//auto res2 = exec->execute(cmd2);

	//auto test_suite_executor = http::RequestExecutor::create({ "http://127.0.0.1:8082" }, "Northwind", {}, set_for_fiddler);
	
	auto test_suite_executor = http::RequestExecutor::create
	({ "https://a.sashatim125.development.run:8085" }, "Northwind", *get_cert(), set_for_verbose);


	//auto test_suite_executor = http::RequestExecutor::create
	//({ "https://alexander-pc:8086" }, "Northwind", *get_cert(), set_for_verbose);


	//documents::commands::GetDocumentsCommand cmd(
	//	std::vector<std::string>{ "employees/1-A", "orders/830-A" }, { "Freight","ReportsTo"}, false);
	//documents::commands::GetDocumentsCommand cmd(0, 20);
	//std::vector<std::string> ids;
	//for(auto i=1;i<=100;++i)
	//{
	//	ids.push_back("employees/" + std::to_string(i) + "-A");
	//}
	//documents::commands::GetDocumentsCommand cmd(ids, {},false);
	//documents::commands::GetDocumentsCommand cmd("employees/", "", "1-A*", "", 0, 16, false);
	//documents::commands::GetDocumentsCommand cmd(
	//		std::vector<std::string>{ "employees/1-A", "employees/3-A", "employees/3-A", "orders/830-A"}, {"Employee","ReportsTo"}, false);
	//test_suite_executor->execute(cmd);

	//documents::indexes::IndexDefinition index{};
	//index.name = "MyIndex";
	//index.maps = 
	//{ 
	//	R"(
	//	from order in docs.Orders 
	//		select new 
	//		{ 
	//			order.Employee, 
	//			order.Company
	//		})"
	//};
	//auto cmd = documents::operations::indexes::PutIndexesOperation({index}).get_command({});
	//auto res = test_suite_executor->execute(*cmd);
	//std::cout << res[0].index_name << std::endl;

	//std::getchar();

	//auto cmd2 = documents::operations::indexes::GetIndexOperation("Orders/ByCompany").get_command({});
	//auto res2 = test_suite_executor->execute(*cmd2);
	//std::cout << res2.name << std::endl;

	//std::getchar();

	//auto cmd3 = documents::operations::indexes::GetIndexesOperation(0,100).get_command({});
	//auto res3 = test_suite_executor->execute(*cmd3);
	//std::cout << res3[1].name << std::endl;

	//std::getchar();

	//auto cmd4 = documents::operations::indexes::IndexHasChangedOperation(index).get_command({});
	//auto res4 = test_suite_executor->execute(*cmd4);
	//std::cout << std::boolalpha << res4 << std::endl;

	//std::getchar();

	//auto cmd5 = documents::operations::indexes::DeleteIndexOperation("MyIndex").get_command({});
	//auto res5 = test_suite_executor->execute(*cmd5);

	//serverwide::operations::DeleteDatabasesOperation op6("something", true, {}, std::chrono::hours(30));
	//auto cmd6 = op6.get_command({});
	//auto res6 = test_suite_executor->execute(*cmd6);

	//auto cmd7 = documents::operations::indexes::EnableIndexOperation("People/Search").get_command({});
	//auto res4 = test_suite_executor->execute(*cmd7);

	//auto cmd8 = documents::operations::indexes::ResetIndexOperation("People/Search").get_command({});
	//auto res8 = test_suite_executor->execute(*cmd8);

	//auto cmd9 = documents::operations::indexes::StopIndexOperation("MyIndex").get_command({});
	//auto res9 = test_suite_executor->execute(*cmd9);

	//auto cmd10 = documents::operations::indexes::StartIndexOperation("MyIndex").get_command({});
	//auto res10 = test_suite_executor->execute(*cmd10);

	//auto cmd11 = documents::operations::indexes::StopIndexingOperation().get_command({});
	//auto res11 = test_suite_executor->execute(*cmd11);

	//auto cmd12 = documents::operations::indexes::StartIndexingOperation().get_command({});
	//auto res12 = test_suite_executor->execute(*cmd12);

	auto cmd14 = documents::operations::indexes::GetIndexNamesOperation(0, 100).get_command({});
	auto res14 = test_suite_executor->execute(*cmd14);
	for(const auto& name : res14)
	{
		std::cout << name << "\n";
	}

	//auto cmd15 = documents::operations::indexes::GetIndexErrorsOperation({ "MyIndex" }).get_command({});
	//auto res15 = test_suite_executor->execute(*cmd15);

	//documents::operations::indexes::set_indexes_lock_op::Parameters params{};
	//params.index_names = { "MyIndex" };// , "Orders/ByCompany" };
	//params.mode = IndexLockMode::UNLOCK;
	//auto cmd16 = ravendb::client::documents::operations::indexes::SetIndexesLockOperation(params)		
	//	.get_command({});
	//auto res16 = test_suite_executor->execute(*cmd16);

	//auto cmd17 = ravendb::client::documents::operations::indexes::GetIndexesStatisticsOperation().get_command({});
	//auto res17 = test_suite_executor->execute(*cmd17);

	//auto cmd18 = ravendb::client::documents::operations::indexes::GetIndexingStatusOperation().get_command({});
	//auto res18 = test_suite_executor->execute(*cmd18);

	//auto cmd19 = ravendb::client::documents::operations::indexes::GetTermsOperation("MyIndex","Company")
	//	.get_command({});
	//auto res19 = test_suite_executor->execute(*cmd19);

	//auto cmd20 = ravendb::client::documents::operations::indexes::SetIndexesPriorityOperation("MyIndex", IndexPriority::UNSET)
	//	.get_command({});
	//auto res20 = test_suite_executor->execute(*cmd20);

	//std::string query = R"(

	//from Employees
	//where StartsWith(FirstName,$prefix)

	//)";

	//documents::queries::IndexQuery indexQuery(query);
	//indexQuery.query_parameters.emplace("prefix", "A");
	//indexQuery.explain_scores = true;
	//indexQuery.show_timings = true;
	//indexQuery.wait_for_non_stale_results = true;
	//indexQuery.wait_for_non_stale_results_timeout = std::chrono::seconds(5);


	//auto cmd = documents::commands::QueryCommand({}, indexQuery, false , false);
	//auto res = test_suite_executor->execute(cmd);
	//for (auto& result : res.results)
	//{
	//	std::cout << result.at("FirstName").get<std::string>() << " " << result.at("LastName").get<std::string>() << " " <<
	//		result.at("Birthday").get<impl::DateTimeOffset>() << "\n";
	//}
	//std::cout << "last query time " << res.last_query_time << "\n";
	//nlohmann::json j = res.last_query_time;
	//std::cout << "last query time " << j << "\n";

	//documents::queries::QueryResult r = res.create_snapshot();

	//std::getchar();



}




//
//
//static size_t writefunction(void *ptr, size_t size, size_t nmemb, void *stream)
//{
//	fwrite(ptr, size, nmemb, (FILE*)stream);
//	return (nmemb*size);
//}
//
//static CURLcode sslctx_function(CURL* , void *sslctx_void, void *cert_details_void)
//{
//	static const auto my_BIO_free = [&](BIO* bio) {if (bio != nullptr) BIO_vfree(bio); };
//	static const auto my_X509_free = [&](X509* cert) {if (cert != nullptr) X509_free(cert); };
//	static const auto my_RSA_free = [&](RSA *rsa) {if (rsa != nullptr) RSA_free(rsa); };
//
//	SSL_CTX* sslctx = static_cast<SSL_CTX*>(sslctx_void);
//	const CertificateDetails& cert_details = *static_cast<const CertificateDetails*>(cert_details_void);
//
//	//create a bio for the certificate
//	auto cert_bio = std::unique_ptr < BIO, decltype(my_BIO_free) > 
//		(BIO_new_mem_buf
//		(cert_details.certificate.c_str(), (int)cert_details.certificate.length()), my_BIO_free);
//	if (!cert_bio) 
//	{
//		throw std::runtime_error("BIO_new_mem_buf failed\n");
//	}
//
//	auto cert = std::unique_ptr < X509, decltype(my_X509_free) >
//		(PEM_read_bio_X509(cert_bio.get(), nullptr, nullptr, nullptr), my_X509_free);
//	if (!cert) 
//	{
//		throw std::runtime_error("PEM_read_bio_X509 failed\n");
//	}
//
//	//tell SSL to use the X509 certificate
//	if (auto ret = SSL_CTX_use_certificate(sslctx, cert.get()); ret != 1)
//	{
//		throw std::runtime_error("Use certificate failed\n");
//	}
//
//	//create a bio for the RSA key
//	auto key_bio = std::unique_ptr < BIO, decltype(my_BIO_free) > 
//		(BIO_new_mem_buf(cert_details.key.c_str(), (int)cert_details.key.length()), my_BIO_free);
//	if (!key_bio) 
//	{
//		throw std::runtime_error("BIO_new_mem_buf failed\n");
//	}
//
//	//read the key bio into an RSA object
//	auto rsa = std::unique_ptr < RSA, decltype(my_RSA_free) >
//		(PEM_read_bio_RSAPrivateKey(key_bio.get(), nullptr, nullptr,
//		 const_cast<char*>(cert_details.key_password.has_value() ? cert_details.key_password.value().c_str() : nullptr)),
//		 my_RSA_free);
//	if (!rsa) 
//	{
//		throw std::runtime_error("Failed to create key bio\n");
//	}
//
//	//tell SSL to use the RSA key
//	if (auto ret = SSL_CTX_use_RSAPrivateKey(sslctx, rsa.get()); ret != 1)
//	{
//		throw std::runtime_error("Use Key failed\n");
//	}
//
//	// all set to go
//	return CURLE_OK;
//}
//
//
//int main(void)
//{
//	CURL *ch;
//	CURLcode rv;
//
//	rv = curl_global_init(CURL_GLOBAL_ALL);
//	ch = curl_easy_init();
//	rv = curl_easy_setopt(ch, CURLOPT_VERBOSE, 0L);
//	rv = curl_easy_setopt(ch, CURLOPT_HEADER, 0L);
//	rv = curl_easy_setopt(ch, CURLOPT_NOPROGRESS, 1L);
//	rv = curl_easy_setopt(ch, CURLOPT_NOSIGNAL, 1L);
//	rv = curl_easy_setopt(ch, CURLOPT_WRITEFUNCTION, writefunction);
//	rv = curl_easy_setopt(ch, CURLOPT_WRITEDATA, stdout);
//	rv = curl_easy_setopt(ch, CURLOPT_HEADERFUNCTION, writefunction);
//	rv = curl_easy_setopt(ch, CURLOPT_HEADERDATA, stderr);
//	rv = curl_easy_setopt(ch, CURLOPT_SSLCERTTYPE, "PEM");
//
//	/* both VERIFYPEER and VERIFYHOST are set to 0 in this case because there is
//	   no CA certificate*/
//
//	rv = curl_easy_setopt(ch, CURLOPT_SSL_VERIFYPEER, 0L);
//	rv = curl_easy_setopt(ch, CURLOPT_SSL_VERIFYHOST, 0L);
//	rv = curl_easy_setopt(ch, CURLOPT_URL, 
//		"https://a.sashatim125.development.run:8085/databases/Northwind/indexes?start=0&pageSize=100&namesOnly=true");
//	rv = curl_easy_setopt(ch, CURLOPT_SSLKEYTYPE, "PEM");
//	rv = curl_easy_setopt(ch, CURLOPT_SSL_CTX_FUNCTION, sslctx_function);
//	rv = curl_easy_setopt(ch, CURLOPT_SSL_CTX_DATA, cert_det);
//	rv = curl_easy_perform(ch);
//	if (rv == CURLE_OK) {
//		printf("*** transfer succeeded ***\n");
//	}
//	else {
//		printf("*** transfer failed ***\n");
//	}
//
//	curl_easy_cleanup(ch);
//	curl_global_cleanup();
//	return rv;
//}
