#!/bin/bash
apt update;apt -y install shtool
libtoolize --force
aclocal
autoheader
automake --force-missing --add-missing
autoconf
./configure
CFLAGS="-Ofast" make -j`nproc`
