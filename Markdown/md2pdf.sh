#!/bin/bash
for f in *.md
      do
      pandoc "$f" -o "${f%.md}.pdf" -V geometry:margin=1in -V fontsize=12pt -V documentclass=extarticle
done