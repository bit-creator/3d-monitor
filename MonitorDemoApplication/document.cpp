#include "document.h"
#include "documentmanager.h"

Document::Document(QString filename)
    : _filename(filename)
{

}

Document::Document(const Document& document)
    : _filename(document._filename)
{

}

Document::Document(const Document&& document)
    : _filename(document._filename)
{

}

Document::~Document()
{

}

bool Document::SaveAs(QString filename)
{
    bool result = false;

    _filename = filename;
    if(Save())
    {
        //result = DocumentManager::GetInstance().RenameDocument(this, filename);
    }

    return result;
}

QString Document::GetName() const
{
    return _filename;
}
