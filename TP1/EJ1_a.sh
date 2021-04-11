#!/bin/bash

ls -l /usr/bin > $HOME/listado
cat $HOME/listado | sort -f -r -k 9 > $HOME/listado.r
