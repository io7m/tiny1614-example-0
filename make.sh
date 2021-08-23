#!/bin/sh -ex

rm -rf build

mkdir -p build

SOURCES="
clockControl.h
integer.h
main.cpp
timerTypeA.h
timerTypeB.h
timerTypeD.h
usart.cpp
usart.h
"

for SOURCE in ${SOURCES}
do
  clang-format -i "${SOURCE}"
done

./as-compile build/vectors.o vectors.s
./as-compile build/setup.o setup.s

./cxx-compile build/usart.o usart.cpp
./cxx-compile build/main.o main.cpp
./cxx-link build/main build/main.o build/usart.o build/setup.o build/vectors.o
./hex build/main.hex build/main

