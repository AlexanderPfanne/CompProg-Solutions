#!/bin/bash

cp --no-clobber code.cc $1/1.cc
cd $1
nvim +6 -O 1.cc input input2 -c ":vertical resize 90"
