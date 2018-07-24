#!/bin/bash

set -e
cd ${0%%$(basename $0)}
rm build -fr
mkdir build
cd build

cmake -GNinja -DCMAKE_BUILD_TYPE=DEBUG .. && ninja
