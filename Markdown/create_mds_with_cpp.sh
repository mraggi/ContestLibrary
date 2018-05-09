#!/bin/bash

mkdir tmp

for f in *.md
	do
	python substitutebycpp.py "$f" > "tmp/$f"
done
