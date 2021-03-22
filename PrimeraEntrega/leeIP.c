#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Siendo Número entre 0 y 255 ==> Ne0y255
//lee una ip de la forma:
// Ne0y255.Ne0y255.Ne0y255.Ne0y255

#define ROJO_T     "\x1b[31m"
#define MAGENTA_T  "\x1b[35m"
#define VERDE_T        "\x1b[32m"
#define CYAN_T     "\x1b[36m"
#define AMARILLO_T "\x1b[33m"
#define AZUL_T     "\x1b[34m"


#define BLANCO_F   "\x1b[47m"

int main(int argc, char *argv[])
{

    /* Captura de errores */


    if(argc != 2){

        if(argc > 2){
            printf(ROJO_T "ERROR:\tIntrodujo mas parametros de los necesarios\n" MAGENTA_T "\tRecuerde:\n\t\t- Ingresar ./leerIP xxx.yyy.zzz.uuu donde cada x,y,z y u son numeros enteros del 0 al 9\n\t\t- En caso de que por ejemplo tener xxx = 001 solo debe ingresar 1 no debe completar con ceros al principio\n");
        }
        else{
            printf(ROJO_T "ERROR:\tIntrodujo menos parametros de los necesarios\n" MAGENTA_T "\tRecuerde:\n\t\t- Ingresar ./leerIP xxx.yyy.zzz.uuu donde cada x,y,z y u son numeros enteros del 0 al 9\n\t\t- En caso de que por ejemplo tener xxx = 001 solo debe ingresar 1 no debe completar con ceros al principio\n");
        }
    }

    else{
        /* Declaración de variables */

        int x,y,z,u,a,i;
        int ipx,ipy,ipz,ip;
        char ipusuario[16];
        /****************************/
        a=0;
        i=0;
        strcpy(ipusuario,argv[1]); // Se almacena el string de entrada como una cadena de caracteres
        /*
        for(i = 0; i<strlen(ipusuario); i++){
            if(isdigit(ipusuario[i]) == 0){
                if(ipusuario[i] != 46){
                    a = 1;
                    break;
                }
            }
        }*/

        while(i < strlen(ipusuario)){
            if(isdigit(ipusuario[i]) == 0){
                if(ipusuario[i] != 46){
                    a = 1;
                }
            }
            i++;
        }

        if(ipusuario[0]=='.'| ipusuario[strlen(ipusuario)-1]=='.'){
            a = 1;
        }

        if(a==0){

            /* Desplazamiento necesarios para que la ip quede conformoda como un solo numero */
            int despx = 24;
            int despy = 16;
            int despz = 8;


            sscanf(argv[1],"%d.%d.%d.%d",&x,&y,&z,&u);

            if(x > 255 | y > 255 | z > 255 | u > 255){
                printf( ROJO_T "ERROR:\tAlguno de los numeros separados por puntos es mayor a 255\n");
            }
            else{
                printf(AMARILLO_T"\tProceso realizado con exito!\n");
                printf(AZUL_T"\t\t- IP ingresada:\t\t%d.%d.%d.%d\n",x,y,z,u);


                ipx = x<<despx;
                ipy = y<<despy;
                ipz = z<<despz;

                ip = ((ipx|ipy)|ipz)|u;

                printf(AZUL_T"\t\t- IP en hexadecimal:\t0x%X\n",ip); // IP en hexadecimal
            }
        }
        else{
            printf(ROJO_T "ERROR:\tVerifique si introdujo algún caracter no permitido\n\t" MAGENTA_T "Los caracteres permitidos son . y numeros\n\tNo comience ni termine con un punto\n");
        }

    }
}
