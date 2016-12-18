#!/bin/bash

# when compiled with -static using default libc, executable still
# has dynamic links, here we use musl alternative to create really
# static executable

# make hello-c CFLAGS='-Os -flto -static -s'
make hello-c CFLAGS='-Os -flto -static -s' CC=musl-gcc
