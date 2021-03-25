#define LOG_TAG "test_Kabir"
#include <utils/RefBase.h>
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <IKabir.h>

using namespace android;
sp < IKabir > gKabir;
const sp < IKabir > &getKabirService()
{
    sp < IServiceManager > sm = defaultServiceManager();
    sp < IBinder > binder;
    do {
        binder = sm->getService(String16("demo.Kabir"));
        if (binder != 0)
            break;
        ALOGW("Service not published, waiting...\n");
        usleep(500000);	// 0.5 s 
    } while (true);

    gKabir = interface_cast < IKabir > (binder);
    ALOGE_IF(gKabir == 0, "no Service!?");
    return gKabir;
}

int main()
{
    getKabirService();
    ALOGW("get instance %p", gKabir.get());
    gKabir->printInfo(100);
    gKabir->printInfo(100, 500);
    return 0;
}
