#include <stdio.h>
#include <stdlib.h>


int main()
{
    char primeiro;
    char segundo;

    printf("Primeiro jogador, escolha pedra(r), papel(p) ou tesoura(t):\n");
    scanf("%c", &primeiro);
    system("clear");
    printf("\nSegundo jogador, escolha pedra(r), papel(p) ou tesoura(t):\n");
    scanf(" %c", &segundo);
    system("clear");

    if (primeiro == segundo) {
        printf("Empate");
    }
    else if (primeiro == 'r' &&  segundo == 'p')
    {
        printf("Segundo jogador ganho krl porra :)");
    }
    else if (primeiro == 'p' &&  segundo == 't')
    {
        printf("Segundo jogador ganho krl porra :)");
    }
    else if (primeiro == 't' &&  segundo == 'r')
    {
        printf("Segundo jogador ganho krl porra :)");
    }
    else
    {
        printf("Primeiro jogador ganhou:D");
    }
    
    printf("\nJogador 1: %c\nJogador 2: %c\n", primeiro, segundo);
    return 0;
}