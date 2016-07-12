LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
ifeq ($(RPC),1)
LOCAL_SRC_FILES:=test_rpc.cpp
LOCAL_SHARED_LIBRARIES := \
	    libutils libbinder liblog
else
LOCAL_SRC_FILES:=test.cpp
LOCAL_SHARED_LIBRARIES := \
	    libkabir libutils libbinder liblog
endif

LOCAL_C_INCLUDES:= $(LOCAL_PATH)/../include \
	    frameworks/base/include/ 


LOCAL_MODULE_TAGS := debug

LOCAL_MODULE:= demoz

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := $(call all-java-files-under,com)
LOCAL_MODULE := kabir
include $(BUILD_JAVA_LIBRARY)
