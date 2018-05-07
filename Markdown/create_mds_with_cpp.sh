#!/bin/bash

for f in *.md
	do
	python substitutebycpp.py "$f" > "withcpp/$f"
done
