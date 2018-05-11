#!/bin/bash

set -e # exit immediately if a command exits with something other than 0

./clang-format-helper.sh
cd Markdown
./create_mds_with_cpp.sh
cp UnitePDFS.sh tmp
cp md2pdf.sh tmp
cd tmp
./md2pdf.sh
./UnitePDFS.sh
cp OneForAll.pdf ..
cd ..
rm -rf tmp
