#! /bin/sh
wget https://curl.se/download/curl-7.80.0.tar.xz
tar -xf curl-7.80.0.tar.xz
cd curl-7.80.0.tar.xz
./configure --with-openssl
make
make install # root