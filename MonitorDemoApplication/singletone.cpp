#include "singletone.h"

singletone& singletone::instance()
{
    static singletone s;
    return s;
}
