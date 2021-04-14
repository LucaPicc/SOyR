    if(cantidad de elementos ingresados por línea de comandos incorrecto)
    {
        if(se pusieron elementos de más)
        {
            imprimir mensaje explicativo;
        }
        else
        {
            imprimir mensaje explicativo (se pusieron elementos de menos);
        }
    }

    else
    {
        //DECLARACIÓN Y ASIGNACIÓN DE VARIABLES;

        Se almacena el string de entrada como una cadena de caracteres;
        
        while(el contador sea menor al largo del string)
        {
            if(el elemento del string NO es un elemento de 0 a 9)
            {
                if(el elemento del string NO es un punto ".")
                {
                    bandera de error = 1;
                }
            }
            contador++;
        }

        if(el primer o último elemento del string es un punto ".")
        {
            bandera de error = 1;
        }

        if(el contador de errores == 0)
        {
            //DECLARACIÓN DE DESPLAZAMIENTOS PARA LOS CAMPOS;

            //ASIGNACIÓN DE CADA CAMPO A SU CORRESPONDIENTE VARIABLE;

            if(ningún campo tiene un número mayor a 255)
            {
                imprimir mensaje de explicativo;
            }
            else
            {
                imprimir mensaje de ingreso de datos exitoso;

                realizar los desplazamientos correspondientes para las variables de cada campo;

                concatenar las variables en un solo número de 32 bits;

                imprimir resultado transformado a hexadecimal;
            }
        }
        else
        {
            imprimir mensaje explicativo;
        }
    }
    FIN 
