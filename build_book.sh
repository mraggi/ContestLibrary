#!/bin/bash

set -e # exit immediately if a command exits with something other than 0

./clang-format-helper.sh
cd Markdown
./create_mds_with_cpp.sh
cp build_mini_book.sh tmp
cp md2pdf.sh tmp
cd tmp
./md2pdf.sh
./build_mini_book.sh
cp OneForAll.pdf ..
cd ..
rm -rf tmp
