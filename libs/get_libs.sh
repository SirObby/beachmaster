#! /bin/bash
wget https://curl.se/download/curl-7.80.0.tar.xz
tar -xf curl-7.80.0.tar.xz
cd curl-7.80.0.tar.xz
./configure --with-openssl
make
make install # root

git clone https://github.com/json-c/json-c.git
mkdir json-c-build
cd json-c-build
cmake ../json-c
make -j4
make install
