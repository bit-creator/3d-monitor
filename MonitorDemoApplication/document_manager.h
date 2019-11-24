#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include "singletone.h"

class Document_manager : public singletone
{
    Document_manager();
    ~Document_manager();
public:
    Document_manager(const Document_manager& document_maneger) = delete;
    Document_manager& operator=(const Document_manager& document_manager) = delete;

    // и что то там еще
};

#endif // DOCUMENT_MANAGER_H
