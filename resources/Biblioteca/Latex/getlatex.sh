#!/bin/bash

g++ -std=c++17 -o getlatex getlatex.cpp -O2
./getlatex $1 > biblioteca.tex
rubber -d biblioteca
# segunda passada: biblioteca.toc so fica correto depois da 1a passada (o
# arquivo eh apagado no fim deste script), entao sem isso o indice sai com
# os numeros de pagina errados/desatualizados
rubber -d biblioteca
mv biblioteca.pdf ../pdf
rm tmp.cpp
rm getlatex biblioteca.aux biblioteca.toc biblioteca.out
rm -f biblioteca.rubbercache