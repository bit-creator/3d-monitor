#ifndef SINGLETONE_H
#define SINGLETONE_H


class singletone
{
    singletone();
    ~singletone();
public:
    singletone(const singletone&) = delete;
    singletone& operator=(const singletone&) = delete;
    static singletone& instance();
};

#endif // SINGLETONE_H
