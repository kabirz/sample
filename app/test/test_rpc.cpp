#define LOG_TAG "RTC_Kabir"
#include <binder/IBinder.h>
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>

using namespace android;
enum {
    NUM_ADD,
    NUM_ADD2
};

sp < IBinder > binder;
void getKabirService()
{
    sp < IServiceManager > sm = defaultServiceManager();
    do {
        binder = sm->getService(String16("demo.Kabir"));
        if (binder != 0)
            break;
        ALOGW("Service not published, waiting...\n");
        usleep(500000);	// 0.5 s 
    } while (true);
}

int main()
{
    Parcel data, reply;
    getKabirService();
    if (binder == NULL) {
        ALOGE("Can't get the instance");
        return -1;
    }

    data.writeInterfaceToken(String16("demo.IKabir"));
    data.writeInt32(300);
    binder->transact(NUM_ADD, data, &reply);
    ALOGW("retrun value is :%d", reply.readInt32());

    data.freeData();
    data.writeInterfaceToken(String16("demo.IKabir"));
    data.writeInt32(300);
    data.writeInt32(900);
    binder->transact(NUM_ADD2, data, &reply);
    ALOGW("%d + %d = %d", 300, 900, reply.readInt32());

    return 0;
}
