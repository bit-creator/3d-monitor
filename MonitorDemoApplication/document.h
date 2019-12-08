#ifndef DOCUMENT_H
#define DOCUMENT_H

#include<fstream>
#include<QString>
#include<memory>

class Document
{
public:
    enum class DocumentType
    {
        MESH_DOCUMENT
    };

    Document(QString filename);
    Document(const Document& document);
    Document(const Document&& document);

    Document& operator=(const Document& document);
    Document& operator=(const Document&& document);

    virtual ~Document();

    virtual DocumentType GetDocumentType() const = 0;

    virtual bool Open() = 0;
    virtual bool Save() = 0;

    bool SaveAs(QString filename);
    QString GetName() const;

    friend std::ifstream& operator>>(std::ifstream& in, Document& document);
    friend std::ofstream& operator<<(std::ofstream& out, Document& document);

private:
    QString _filename;
};

#endif // DOCUMENT_H
