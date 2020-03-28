#!/bin/bash
apt update;apt -y install shtool libtool libtool-bin autoconf automake build-essential
mkdir build-aux m4
libtoolize --force
aclocal
autoheader
automake --force-missing --add-missing
autoconf
./configure
CFLAGS="-Ofast" make -j`nproc`
echo Now run 'make install' if you want to install it
