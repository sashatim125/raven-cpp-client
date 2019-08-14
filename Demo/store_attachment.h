#pragma once
#include "raven_cpp_client.h"
#include <fstream>


namespace demo
{
	//ATTENTION!
	//In the session.advanced().attachments()->store_attachment() method the attachment stream
	//is passed by reference(!). So the stream must be available for input(reading from it)
	//at the time of actual command sending(like session.save_changes()).
	inline void storeAttachment(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& documentID,
		const std::filesystem::path& attachmentFilePath,
		const std::string& contentType);
}
