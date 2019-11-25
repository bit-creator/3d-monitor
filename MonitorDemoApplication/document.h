#ifndef DOCUMENT_H
#define DOCUMENT_H

#include<QTextStream>

class Document
{
public:
    Document();
    Document(const Document& document);
    Document(const Document&& document);

    Document& operator=(const Document& document);
    Document& operator=(const Document&& document);

    enum class Document_Type {STL, OBJ};

    virtual Document_Type get_document_type() = 0;

    virtual ~Document();

    friend QTextStream& operator>>(QTextStream& in, Document& document);
    friend QTextStream& operator<<(QTextStream& out, Document& document);
};

#endif // DOCUMENT_H
