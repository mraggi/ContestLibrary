#!/bin/bash

#./clang-format-helper.sh
cd Markdown
./create_mds_with_cpp.sh
cp build_mini_book.sh tmp
cd tmp
md2pdf
./build_mini_book.sh
cp OneForAll.pdf ..
cd ..
rm -rf tmp