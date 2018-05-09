#!/bin/bash

#./clang-format-helper.sh
cd Markdown
./create_mds_with_cpp.sh
cd withcpp
md2pdf
./build_mini_book.sh
