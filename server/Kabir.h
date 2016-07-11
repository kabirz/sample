#include <binder/BinderService.h>
#include "IKabir.h"
namespace android {
class Kabir:public BinderService < Kabir >, public BnKabir, protected Thread {
public:
    static char const *getServiceName()
    {
        return "demo.Kabir";
    }
    Kabir();
    virtual void printInfo(int value);
    virtual void printInfo(int a, int b);
    virtual ~ Kabir();
    virtual status_t onTransact(uint32_t code, const Parcel & data,
            Parcel * reply, uint32_t flags);
    virtual bool threadLoop();
};

};				// namespace android
