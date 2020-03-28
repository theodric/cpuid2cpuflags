#!/bin/bash
apt update;apt -y install shtool
mkdir build-aux m4
libtoolize --force
aclocal
autoheader
automake --force-missing --add-missing
autoconf
./configure
CFLAGS="-Ofast" make -j`nproc`
