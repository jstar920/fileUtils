#!/bin/bash
DIR="mac_x64_output"
if [ -d "$DIR" ]; then
  rm -rf $DIR
fi

mkdir $DIR
cd $DIR
cmake .. -G "Unix Makefiles"
cd ..
