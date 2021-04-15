Asignación de la dirección del directorio creado a la variable dir
Asignación de la dirección del archivo creado a la variable file

if [número de argumentos pasados es distinto de 2];
then
	Mensaje explicativo de ERROR;
elif [se pasa un punto “.” o una barra “/” en alguno de los argumentos];
then
	Mensaje explicativo de ERROR;
elif [ya existe un directorio con el nombre pasado];
then
	Mensaje explicativo de ERROR;
elif [ya existe un archivo con el nombre pasado en HOME];
then
	Mensaje explicativo de ERROR;
else

	Se crea el directorio en dir
	Se buscan y se copian los archivos que terminan en “.conf” y donde el resto del mundo tienen permisos de lectura al directorio

	Se quitan todos los permisos para grupos y resto del mundo

	Se escriben en file, del contenido del directorio listado en orden creciente de tamaño, los primeros 5 archivos 
	Se escriben a continuación, del contenido del directorio listado alfabética y decrecientemente, los últimos 5 archivos.

fi
