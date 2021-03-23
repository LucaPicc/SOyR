#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones/funciones.h"

#define ROJO_T     "\x1b[31m"
#define MAGENTA_T  "\x1b[35m"
#define VERDE_T    "\x1b[32m"
#define CYAN_T     "\x1b[36m"
#define AMARILLO_T "\x1b[33m"
#define AZUL_T     "\x1b[34m"
#define BLANCO_F   "\x1b[47m"


int main(int argc, char *argv[])
{
    int a;
    char ipusuario[16];

    a = verfArg(argc);
    if( a == 0){
        strcpy(ipusuario,argv[1]); // Se almacena el string de entrada como una cadena de caracteres

        a = verificacionpuntnum(ipusuario);
        
        if(a==0){
            ipHexa(ipusuario);            
        }
        else{
            printf(ROJO_T "ERROR:\tVerifique si introdujo algún caracter no permitido\n\t" MAGENTA_T "Los caracteres permitidos son . y numeros\n\tNo comience ni termine con un punto\n");
        }
    }
}



