#!/bin/bash

clear
echo "# =========================================================================== #"
echo "COMPILANDO PROYECTO..."
echo "# =========================================================================== #"

gcc -Wall -g -std=c99 \
        main.c lib_hour.h lib_hour.c ArrayList.h ArrayList.c \
    -o build/app


cd build/

if [ -f app ]; then
#clear
echo "Binario generado con éxito..."
echo "# =========================================================================== #"
echo "Desea ejecutar el programa? [s/n]: "
read resp

    if [[ $resp == 's' ]]; then
        ./app
    elif [[ $resp == 'n' ]]; then
        clear
        echo "# =========================================================================== #"
        echo "Sólo se deja el archivo compilado"
        echo "# =========================================================================== #"
    else
        echo "# =========================================================================== #"
        echo "Debe responder con s o n"
        echo "# =========================================================================== #"
    fi

else
clear
echo "# =========================================================================== #"
echo "El binario no se ha compilado correctamente..."
echo "# =========================================================================== #"
fi
