//Quarto exercício desenvolvido pelo professor;
//Unir coleções de quadrinhos de duas lojas, Deve retornar um ponteiro para um terceiro vetor e outro para o tamanho da coleção.

#include <stdio.h>
#include <stdlib.h>


int* unirColecoes(int colecaoHeroisHQ[], int colecaoAComics[], int tamanhoHeroisHQ, int tamanhoAComics, int* tamanhoFinal) {
    *tamanhoFinal = tamanhoHeroisHQ + tamanhoAComics;
    int *colecaoUnificada = (int *)malloc(sizeof(int) * (*tamanhoFinal));
    
    if (colecaoUnificada == NULL) {
        return NULL;
    }

    for (int i = 0; i < tamanhoHeroisHQ; i++) {
        colecaoUnificada[i] = colecaoHeroisHQ[i];
    }

    for (int i = 0; i < tamanhoAComics; i++) {
        colecaoUnificada[tamanhoHeroisHQ + i] = colecaoAComics[i];
    }

    return colecaoUnificada;
}

int main() {
    int colecaoHeroisHQ[] = {101, 102, 103, 104};
    int colecaoAComics[] = {201, 202, 203};
    int tamanhoHeroisHQ = 4;
    int tamanhoAComics = 3;
    int tamanhoFinal;

    int *colecaoUnificada = unirColecoes(colecaoHeroisHQ, colecaoAComics, tamanhoHeroisHQ, tamanhoAComics, &tamanhoFinal);

    return 0;
}