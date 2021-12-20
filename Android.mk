# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


################################################################################################################
# NOTICE:
# IN ORDER TO BUILD THIS PROJECT, YOU MUST CREATE AN ndkpath.txt IN THE SAME DIRECTORY AS THIS FILE
# WITH A PATH TO YOUR NDK DIRECTORY (TYPICALLY c:/android-ndk-r20b OR SIMILAR)
# THEN RUN build.ps1
################################################################################################################

LOCAL_PATH := $(call my-dir)
TARGET_ARCH_ABI := $(APP_ABI)

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# Creating prebuilt for dependency: modloader - version: 1.2.3
include $(CLEAR_VARS)
LOCAL_MODULE := modloader
LOCAL_EXPORT_C_INCLUDES := extern/modloader
LOCAL_SRC_FILES := extern/libmodloader.so
include $(PREBUILT_SHARED_LIBRARY)
# Creating prebuilt for dependency: capstone - version: 0.1.0
include $(CLEAR_VARS)
LOCAL_MODULE := capstone
LOCAL_EXPORT_C_INCLUDES := extern/capstone
LOCAL_SRC_FILES := extern/libcapstone.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := beatsaber-hook_3_4_2
LOCAL_SRC_FILES += $(call rwildcard,src/utils,*.cpp)
LOCAL_SRC_FILES += $(call rwildcard,src/config,*.cpp)
LOCAL_SHARED_LIBRARIES += modloader
LOCAL_STATIC_LIBRARIES += capstone
LOCAL_LDLIBS += -llog
LOCAL_CFLAGS += -DVERSION='"3.4.2"' -isystem 'extern/libil2cpp/il2cpp/libil2cpp' -D'UNITY_2019' -Wall -Wextra -Werror -Wno-unused-function -DID='"beatsaber-hook"' -I'./shared' -isystem 'extern'
LOCAL_C_INCLUDES += ./shared
LOCAL_CPP_FEATURES += exceptions rtti
include $(BUILD_SHARED_LIBRARY)
