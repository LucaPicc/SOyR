#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/*          Colores          */

#define ROJO_T     "\x1b[31m"
#define MAGENTA_T  "\x1b[35m"
#define VERDE_T    "\x1b[32m"
#define CYAN_T     "\x1b[36m"
#define AMARILLO_T "\x1b[33m"
#define AZUL_T     "\x1b[34m"
#define BLANCO_F   "\x1b[47m"


/*          Funciones                   */

/* verificacionpuntnum
 *  Esta función se encargara de verificar si la cadena de caracteres introducida posee solo puntos 
 * y numeros
*/
int verificacionpuntnum(char *ip){
    int i,a;
    i=0;
    a=0;
    while(i < strlen(ip)){
            if(isdigit(ip[i]) == 0){
                if(ip[i] != 46){
                    a = 1;
                }
            }
            i++;
        }

        if(ip[0]=='.'| ip[strlen(ip)-1]=='.'){
            a = 1;
        }
    return a;
}

/*ipHexa
 * Función encargada de recibir una ip tipo xxx.yyy.zzz.uuu y devolverla
 * como un numero hexadecimal
*/

int ipHexa(char *ip){
    int despx = 24;
    int despy = 16;
    int despz = 8;

    int ipx,ipy,ipz,iphex,x,y,z,u;


    sscanf(ip,"%d.%d.%d.%d",&x,&y,&z,&u);

    if(x > 255 | y > 255 | z > 255 | u > 255){
        printf( ROJO_T "ERROR:\tAlguno de los numeros separados por puntos es mayor a 255\n");
        return 1;
    }
    else{
        printf(AMARILLO_T"\tProceso realizado con exito!\n");
        printf(AZUL_T"\t\t- IP ingresada:\t\t%d.%d.%d.%d\n",x,y,z,u);

        ipx = x<<despx;
        ipy = y<<despy;
        ipz = z<<despz;

        iphex = ((ipx|ipy)|ipz)|u;
        printf(AZUL_T"\t\t- IP en hexadecimal:\t0x%X\n",iphex); // IP en hexadecimal
        return 0;
    }
}

/*verfArg
 * Función encargada de verificar la cantidad de argumentos introducidos en el main
*/

int verfArg(int r){
    if(r != 2){
        if(r > 2){
            printf(ROJO_T "ERROR:\tIntrodujo mas parametros de los necesarios\n" MAGENTA_T "\tRecuerde:\n\t\t- Ingresar ./leerIP xxx.yyy.zzz.uuu donde cada x,y,z y u son numeros enteros del 0 al 9\n\t\t- En caso de que por ejemplo tener xxx = 001 solo debe ingresar 1 no debe completar con ceros al principio\n");
        }
        else{
            printf(ROJO_T "ERROR:\tIntrodujo menos parametros de los necesarios\n" MAGENTA_T "\tRecuerde:\n\t\t- Ingresar ./leerIP xxx.yyy.zzz.uuu donde cada x,y,z y u son numeros enteros del 0 al 9\n\t\t- En caso de que por ejemplo tener xxx = 001 solo debe ingresar 1 no debe completar con ceros al principio\n");
        }
        return 1;
    }
    return 0;
}
