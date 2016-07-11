#include <binder/BinderService.h>
#include <Kabir.h>
using namespace android;
int main()
{
    ALOGW("servcie:%s running...", Kabir::getServiceName());
    Kabir::publishAndJoinThreadPool();
    ALOGW("servcie:%s end", Kabir::getServiceName());
	return 0;
}
