#!/bin/bash

USE_MESON=1
set -e
cd ${0%%$(basename $0)}
rm build -fr
mkdir build
cd build
if [ $USE_MESON -eq 1 ];then
	meson ..
else
	cmake -GNinja -DCMAKE_BUILD_TYPE=DEBUG ..
fi

if [ $? -eq 0 ]; then
	ninja
fi
