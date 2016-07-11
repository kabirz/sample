LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:=test.cpp

LOCAL_SHARED_LIBRARIES := \
	    libkabir libutils libbinder liblog

LOCAL_C_INCLUDES:= $(LOCAL_PATH)/../include \
	    frameworks/base/include/ 


LOCAL_MODULE_TAGS := debug

LOCAL_MODULE:= demoz

include $(BUILD_EXECUTABLE)
