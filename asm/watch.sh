#!/usr/bin/env bash
while inotifywait -e delete_self tiny.asm ; do ./build.sh ; done
