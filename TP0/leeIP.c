/* Ejercicio 9 Practica 0
 * 
 * Autores:
 *      Moreyra Iñigo, Juan Martín
 *      Piccinini Luca
 *      Taboada Rodney
 *
 * El objetivo del programa es recibir una ip en formato xxx.yyy.zzz.uuu
 * y devolverla en hexadecimal
 */

/* Parametros de salida
 *      - Si la función retorna -1 la cantidad de argumentos es erronea
 *      - Si la función retorna -2 alguno de los caracteres del argumento es erroneo
 *      - Si la función retorna -3 el argumento comenzo o termino en "."
 *      - Si la función retorna -4 alguno de los conjuntos de 3 numeros es mayor a 255
 *      - Si la función retorna  0 si no hubo ningun error
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int flag_error, i, ip, ipx, ipy, ipz, x, y, z, u, despz, despy, despx;
    char ipusuario[16];
    
    i = 0;
    flag_error = 0;
    despx = 24;
    despy = 16;
    despz = 8;

    /* Verificamos si la cantidad de argumentos es la correcta */
    if(argc != 2){
        if(argc > 2){
            printf("ERROR:\tIntrodujo mas parametros de los necesarios\n\tRecuerde:\n"
                    "\t\t- Ingresar ./leerIP xxx.yyy.zzz.uuu donde cada x,y,z y u son numeros enteros del 0 al 9\n"
                    "\t\t- En caso de que por ejemplo tener xxx = 001 solo debe ingresar 1 no debe completar con ceros" 
                    "al principio\n");
        }else{
            printf("ERROR:\tIntrodujo menos parametros de los necesarios\n\tRecuerde:\n"
                    "\t\t- Ingresar ./leerIP xxx.yyy.zzz.uuu donde cada x,y,z y u son numeros enteros del 0 al 9\n"
                    "\t\t- En caso de que por ejemplo tener xxx = 001 solo debe ingresar 1 no debe completar con ceros" 
                    "al principio\n");
        }
        flag_error = -1;
    }


   if( flag_error == 0){
        strcpy(ipusuario,argv[1]); // Se almacena el string de entrada como una cadena de caracteres

        /* Verificación de argumentos*/
        while(i < strlen(ipusuario)){
            /* Verificamos que todos los argumentos sean digitos o puntos */
            if(isdigit(ipusuario[i]) == 0){
                /* La función isdigit devuelve 0 si el caracter etregado es un digito */
                if(ipusuario[i] != 46){
                    /* Comparamos con 46 que es el numero ascii relacionado con el "." */
                    flag_error = -2;
                }
            }
            i++;
        }
        /* Vericamos que no comience en punto o termine en punto */
        if(ipusuario[0]=='.'| ipusuario[strlen(ipusuario)-1]=='.'){
            flag_error = -3;
        }

        if(flag_error == 0){
            sscanf(ipusuario,"%d.%d.%d.%d",&x,&y,&z,&u);
            
            /* Verificamos no tener valores mayores a 255 */
            if(x > 255 | y > 255 | z > 255 | u > 255){
                flag_error = -4;
                printf("ERROR: Alguno de los conjuntos de 3 numeros es mayor a 255");
            }else{
                /* Desplazamos los bits correspondiente a cada conjunto de numeros */
                ipx = x<<despx;
                ipy = y<<despy;
                ipz = z<<despz;
                /* Obtenemos el numero IP sin puntos */
                ip = ((ipx|ipy)|ipz)|u;
                printf("IP introducida en formato xxx.yyy.zzz.uuu en hexadecimal : 0x%08x\n", ip);
            }
       }else{
            printf("ERROR:\tVerifique si introdujo algún caracter no permitido\n"
                    "\tLos caracteres permitidos son . y numeros\n\tNo comience ni termine con un punto\n");
        }
    }
   return flag_error;
}


