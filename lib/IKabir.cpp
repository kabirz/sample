#define LOG_TAG "IKabir"
#include <stdint.h>
#include <utils/Errors.h>
#include <sys/types.h>
#include <binder/Parcel.h>
#include "IKabir.h"

namespace android {

class BpKabir:public BpInterface < IKabir > {
public:
    BpKabir(const sp < IBinder > &impl):BpInterface < IKabir > (impl) 
    {
    }

    virtual void printInfo(int value)
    {
        Parcel data, reply;
        data.
            writeInterfaceToken(IKabir::
                    getInterfaceDescriptor());
        data.writeInt32(value);
        remote()->transact(NUM_ADD, data, &reply);
        ALOGW("%d + 300 = %d", value, reply.readInt32());
    }
    virtual void printInfo(int a, int b)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IKabir:: getInterfaceDescriptor());
        data.writeInt32(a);
        data.writeInt32(b);
        remote()->transact(NUM_ADD2, data, &reply);
        ALOGW("%d + %d = %d", a, b, reply.readInt32());
    }
};

IMPLEMENT_META_INTERFACE(Kabir, "demo.IKabir");
#if 0
status_t BnKabir::onTransact(uint32_t code, const Parcel & data,
        Parcel * reply, uint32_t flags) 
{
    switch (code) {
        case NUM_ADD:
            int value = data.readInt32();
            printInfo(value);
            reply->writeInt32(value + 300);
            break;
        case NUM_ADD2:
            int a = data.readInt32();
            int b = data.readInt32();
            printInfo(a, b);
            reply->writeInt32(a + b);
            break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
    return NO_ERROR;
}
#endif

};				// namespace android
