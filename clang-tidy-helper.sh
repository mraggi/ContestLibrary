#!/bin/bash

rm -rf ct-build
mkdir ct-build
cd ct-build

cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_CLANG_TIDY:STRING="clang-tidy;--header-filter=.*;-checks=*,-google-readability-braces-around-statements,-readability-braces-around-statements,-fuchsia-*,-hicpp-braces-around-statements,-llvm-header-guard,-misc-unused-parameters,-google-runtime-references,-google-explicit-constructor,-hicpp-explicit-conversions,-readability-implicit-bool-conversion,-google-runtime-int" ..
# cmake -DBUILD_TESTS=OFF -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_CLANG_TIDY:STRING="clang-tidy;--header-filter=.*;-fix;-checks=*,-google-readability-braces-around-statements,-readability-braces-around-statements,-fuchsia-*,-hicpp-braces-around-statements,-llvm-header-guard,-misc-unused-parameters,-google-runtime-references,-google-explicit-constructor,-hicpp-explicit-conversions,-readability-implicit-bool-conversion" ..
make
