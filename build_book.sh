#!/bin/bash

./clang-format-helper.sh
cd Markdown
mkdir -p tmp
cp preamble.tex tmp
cp template.latex tmp
./create_mds_with_cpp.sh
cd tmp
cat Content.md \
    GCDAndModInverse.md \
    PrimeSieve.md \
    LongestIncreasingSubsequence.md \
    DisjointSets.md \
    DisjointIntervals.md \
    RangeMinQuery.md \
    LinearProgramming.md \
    NaturalNumber.md \
    Graph.md \
    ConnectedComponents.md \
    Trees.md \
    MST.md \
    LCA.md \
    ShortestPath.md \
    BipartiteGraph.md \
    BipartiteMatching.md \
    MaxFlow.md \
    > OneForAll.md
sed -i 's/^## \(.*\)/\\newpage\n## \1/g' OneForAll.md
# tail -n +2 OneForAll.md > OFA.md
pandoc OneForAll.md -o OneForAll.pdf -H preamble.tex --template=template.latex -V geometry:margin=1in -V fontsize=12pt
# cp OneForAll.md ..
# cp OFA.md ..
cp OneForAll.pdf ..
cd ..
# rm -rf tmp