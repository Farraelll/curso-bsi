//Quinto exercício desenvolvido pelo professor;
//O objetivo é dividir uma string em duas, usando um espaço como divisor.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dividirTexto(char *entrada, char *parte1, char *parte2) {
    
    if (strchr(entrada, ' ') == NULL) {
        return 0;
    }
    sscanf(entrada, "%s %s", parte1, parte2);
    return 1;
}

int main() {
    char texto[] = "Bom dia";
    char parte1[20];
    char parte2[20];

    if (dividirTexto(texto, parte1, parte2)) {
        printf("Mensagem original: %s\n", texto);
        printf("Parte 1: %s\n", parte1);
        printf("Parte 2: %s\n", parte2);
    } else {
        printf("A string não contém espaço para divisão.\n");
    }

    return 0;
}