#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <list>
#include "model.h"

class Document_manager
{
    Document_manager();
    ~Document_manager();
public:
    Document_manager(const Document_manager& document_maneger) = delete;
    Document_manager& operator=(const Document_manager& document_manager) = delete;

    static Document_manager& get_instance();

    void set_model(QTextStream& in);            //нужно ли возвращять поток
    void change_active_model(int);
    void remove_active_model(void);
    void delete_all_model(void);
    void save_active_model(QTextStream& out);   //нужно ли возвращять поток

private:
    std::list<Model> _model_data;
    std::list<Model>::iterator _reference;
};

#endif // DOCUMENT_MANAGER_H
