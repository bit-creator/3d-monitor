#include "document_manager.h"

Document_manager& Document_manager::get_instance()
{
    static Document_manager manager;
    return manager;
}

Document_manager::Document_manager(){}

Document_manager::~Document_manager(){}
