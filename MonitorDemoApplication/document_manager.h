#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

class Document_manager
{
    Document_manager();
    ~Document_manager();
public:
    Document_manager(const Document_manager& document_maneger) = delete;
    Document_manager& operator=(const Document_manager& document_manager) = delete;

    static Document_manager& get_instance();
};

#endif // DOCUMENT_MANAGER_H
