#!/bin/bash

for f in *.hpp 
    do
    echo "#pragma once" | cat - "$f" > "$f.tmp";
    mv "$f.tmp" "$f"
done
