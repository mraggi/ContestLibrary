[![Build Status](https://travis-ci.org/mraggi/ContestLibrary.svg?branch=master)](https://travis-ci.org/mraggi/ContestLibrary)
[![Coverage Status](https://coveralls.io/repos/github/mraggi/ContestLibrary/badge.svg?branch=master)](https://coveralls.io/github/mraggi/ContestLibrary?branch=master)
[![license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/mraggi/ContestLibrary/blob/master/LICENSE)

# Algorithms for Contests

A collection of useful algorithms to use in contests such as the ACM ICPC, hackerrank, etc.

See [the printable booklet.](https://github.com/mraggi/ContestLibrary/blob/master/Markdown/OneForAll.pdf) 

Run ./build_book.sh to build the book after modifying a source file. Note that some processing takes place, such a removing the "inline" keyword from .hpp files, as it is not needed in contests, where a single cpp file is submitted.


Requires:
- pandoc
- clang and clang-format
- fd
- latex
- ?

## TODO:

### Already programmed, needs cleanup, etc.
- Geometry: Points, lines, segments, convex hulls, etc.
- Sequences: binomial, stirling numbers, etc.
- Lagrange Interpolation
- Polynomials, maybe fourier transforms
- Simple matrices
- Splay trees ("ropes")
- String stuff: Suffix trees, etc.

### Not yet programmed:
- Segment Trees
- Fenwick Trees
- KD trees
- ???

## Thanks to:
- All my students
- ENES Morelia
- Dr. Jaehyun Park, for releasing his code (for simplex and max flow) with MIT License

## Contributing
We welcome contributions! We value clean, modern C++ Object Oriented code, so don't use C-style code,  macros, etc. Don't worry about formatting (use whatever style you like), since we use clang-format and clang-tidy before commiting anything.
