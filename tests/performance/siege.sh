#!/bin/sh

siege --time=2m -v -c 30 -i -b -f urls.txt --log=./siege.log
