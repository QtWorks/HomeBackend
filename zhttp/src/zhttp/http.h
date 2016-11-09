#ifndef HTTP_H
#define HTTP_H


#include <memory>
#include <include/zcommon/zserviceinterface.h>

class Http : public ZServiceInterface {
public:
    Http();
    virtual ~Http();

public:
    virtual bool initialize();
    virtual bool start();
    virtual bool stop();
    virtual bool cleanup();

private:
    class Impl;
    std::shared_ptr<Impl> d_ptr;
};

#endif // HTTP_H
