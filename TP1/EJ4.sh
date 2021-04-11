#!/bin/bash


ls -l /usr/bin/ > $HOME/EJ4/listado.txt

cat $HOME/EJ4/listado.txt | sort -f -r -k 9 > $HOME/EJ4/listador.txt

cat $HOME/EJ4/listado.txt | sort -n -k 5 > $HOME/EJ4/listadon.txt

more $HOME/EJ4/listador.txt && echo "----------listadon.txt------------" && more $HOME/EJ4/listadon.txt
