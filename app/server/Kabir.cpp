#define LOG_TAG "Kabir"
#include <Kabir.h>
#include <utils/Log.h>

namespace android {

Kabir::Kabir():BnKabir(), Thread(false)
{
}
Kabir::~Kabir()
{
}

status_t Kabir::onTransact(uint32_t code, const Parcel & data,
        Parcel * reply, uint32_t flags)
{
    int value, value2;
    switch (code) {
        case NUM_ADD:
            CHECK_INTERFACE(IKabir, data, reply);
            value = data.readInt32();
            printInfo(value);
            reply->writeInt32(value + 300);
            break;
        case NUM_ADD2:
            CHECK_INTERFACE(IKabir, data, reply);
            value = data.readInt32();
            value2 = data.readInt32();
            printInfo(value, value2);
            reply->writeInt32(value + value2);
            break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
    return NO_ERROR;
}

void Kabir::printInfo(int value)
{
    ALOGW("server:printInfo, value:%d", value);
}

void Kabir::printInfo(int a, int b)
{
    ALOGW("server:printInfo, a:%d, b:%d", a, b);
}

bool Kabir::threadLoop()
{
    return true;
}

};				// namespace android
