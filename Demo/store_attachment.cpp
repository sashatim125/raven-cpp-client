#include "pch.h"
#include "store_attachment.h"

namespace demo
{
	void storeAttachment(std::shared_ptr<ravendb::client::documents::IDocumentStore> store,
		const std::string& documentID,
		const std::filesystem::path& attachmentFilePath,
		const std::string& contentType)
	{
		const auto fileName = attachmentFilePath.filename().string();
		auto file = std::ifstream{attachmentFilePath};

		if (!file)
		{
			throw std::runtime_error("Could not open the attachment file " + attachmentFilePath.string());
		}

		auto session = store->open_session();

		session.advanced().attachments()->store_attachment(documentID, fileName, file, contentType);

		session.save_changes();
	}
}
