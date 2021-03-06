#!/bin/bash
mkdir build-aux m4
glibtoolize --force
aclocal
autoheader
automake --force-missing --add-missing
autoconf
./configure
CFLAGS="-Ofast" make -j`nproc`
echo Now run 'make install' if you want to install it
