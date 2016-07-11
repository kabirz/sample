#include <binder/BinderService.h>
#include "Kabir.h"
using namespace android;
int main()
{
	Kabir::publishAndJoinThreadPool();
	return 0;
}
