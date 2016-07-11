#ifndef ANDROID_IMYBINDER_H
#define ANDROID_IMYBINDER_H
#include <stdint.h>
#include <sys/types.h>
#include <utils/RefBase.h>
#include <utils/Errors.h>
#include <binder/IInterface.h>
namespace android {

enum {
    NUM_ADD;
    NUM_ADD2;
};
// ---------------------------------------------------------------------------- 
class IKabir:public IInterface {
public:
    DECLARE_META_INTERFACE(Kabir);
    virtual void printInfo(int value) = 0;
    virtual void printInfo(int a, int b) = 0;
};
// ---------------------------------------------------------------------------- 
class BnKabir:public BnInterface < IKabir > {
public:
    virtual status_t onTransact(uint32_t code, const Parcel & data,
            Parcel * reply, uint32_t flags =
            0) = 0;
;
// ---------------------------------------------------------------------------- 
};				// namespace android

#endif
