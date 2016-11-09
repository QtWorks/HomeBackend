#ifndef ZSOCKET_H
#define ZSOCKET_H

#include <memory>
#include <include/zcommon/zserviceinterface.h>

class ZSocket : public ZServiceInterface {
public:
    ZSocket();
    virtual ~ZSocket();

public:
    virtual bool initialize();
    virtual bool start();
    virtual bool stop();
    virtual bool cleanup();

private:
    class Impl;
    std::shared_ptr<Impl> d_ptr;
};

#endif // ZSOCKET_H
