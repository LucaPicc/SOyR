
if(verificamos que la cantidad de arguntas sean 2){
    crea directorio con nombre ingresado como primer argumento en home;
    
    copia los archivos con extension .conf en el directorio creado;
    
    se quitan todos los permisos a grupo y al resto del mundo a todos 
    los archivos cuya tercera letra de su nombre sea una "g";
    
    se copian los primeros 5 archivos en orden creciente por tamaño en
    el archivo creado, con nombre del segundo argumento;
    
    se copian los últimos 5 archivos ordenados alfabeticamente en orden 
    decreciente al final del archivo;
}
else{
    se imprime mensaje de error
}
FIN

