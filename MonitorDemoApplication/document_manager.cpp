#include "document_manager.h"

Document_manager& Document_manager::get_instance()
{
    static Document_manager manager;
    return manager;
}

Document_manager::Document_manager(){}

Document_manager::~Document_manager(){}

void Document_manager::set_model(QTextStream& in)
{
    Model model;
    in >> model;
    _model_data.push_back(model);
    _reference = _model_data.end();
}
void Document_manager::change_active_model(int dif)
{
    std::list<Model>::iterator iter = _model_data.begin();
    for(; iter != _model_data.end() && dif != 0; ++iter){--dif;}
    _reference = iter;
}
void Document_manager::remove_active_model(void)
{
    _model_data.remove(*_reference);
}
void Document_manager::delete_all_model(void)
{
    _model_data.clear();
}
void Document_manager::save_active_model(QTextStream& out)
{
    out << const_cast<const decltype (*_reference)>(*_reference);
}
