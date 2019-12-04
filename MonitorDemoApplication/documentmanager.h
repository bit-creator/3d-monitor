#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <map>
#include "Document.h"

class DocumentManager
{
private:
    DocumentManager();

public:
    static DocumentManager& GetInstance();

    std::shared_ptr<Document> OpenDocument(QString filename, Document::DocumentType type);
    bool SaveDocumentAs(std::shared_ptr<Document> document, QString filename);
    bool SaveDocument(std::shared_ptr<Document> document);
    bool CloseDocument(std::shared_ptr<Document> document);

    std::shared_ptr<Document> GetActiveDocument();

private:
    bool RenameDocument(std::shared_ptr<Document>, QString new_filename);

    std::shared_ptr<Document> CreateDocumentByType(QString filename, Document::DocumentType type);

private:
    std::map<QString, std::shared_ptr<Document>> _open_documents;
    std::shared_ptr<Document> _active_document;

    friend bool Document::SaveAs(QString filename);
};

#endif // DOCUMENTMANAGER_H
