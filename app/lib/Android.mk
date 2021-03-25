LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= IKabir.cpp

LOCAL_SHARED_LIBRARIES := \
	    libutils libbinder liblog

LOCAL_C_INCLUDES:= $(LOCAL_PATH)/../include \
	    frameworks/base/include/ 


LOCAL_MODULE_TAGS := debug

LOCAL_MODULE:= libkabir

include $(BUILD_SHARED_LIBRARY)
