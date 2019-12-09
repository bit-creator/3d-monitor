#include "documentmanager.h"
#include "modelstl.h"

DocumentManager::DocumentManager()
    : _active_document(nullptr)
{

}

DocumentManager& DocumentManager::GetInstance()
{
    static DocumentManager instance;
    return instance;
}

std::shared_ptr<Document> DocumentManager::OpenDocument(QString filename, Document::DocumentType type)
{
    std::shared_ptr<Document> document = CreateDocumentByType(filename, type);

    document->Open();

    _open_documents.insert(std::pair<QString,std::shared_ptr<Document>>(filename, document));

    return document;
}

bool DocumentManager::SaveDocumentAs(std::shared_ptr<Document> document, QString filename)
{
    return document->SaveAs(filename);
}

bool DocumentManager::SaveDocument(std::shared_ptr<Document> document)
{
    return document->Save();
}

bool DocumentManager::CloseDocument(std::shared_ptr<Document> document)
{
    bool result = false;

    auto iterator = _open_documents.find(document->GetName());
    if(iterator != _open_documents.end())
    {
        _open_documents.erase(iterator);
        result = true;
    }

    return result;
}

std::shared_ptr<Document> DocumentManager::GetActiveDocument()
{
    return _active_document;
}

bool DocumentManager::RenameDocument(std::shared_ptr<Document> document, QString new_filename)
{
    bool result = false;

    auto iterator = _open_documents.find(document->GetName());
    if(iterator != _open_documents.end())
    {
        _open_documents.erase(iterator);
        _open_documents.insert(std::pair<QString,std::shared_ptr<Document>>(new_filename, document));
        result = true;
    }

    return result;
}

std::shared_ptr<Document> DocumentManager::CreateDocumentByType(QString filename, Document::DocumentType type)
{
    std::shared_ptr<Document> result = nullptr;

    if(type == Document::DocumentType::MESH_DOCUMENT)
    {
        result = std::make_shared<ModelSTL>(filename);  // нуждаеться в доработке
    }

    return result;
}
