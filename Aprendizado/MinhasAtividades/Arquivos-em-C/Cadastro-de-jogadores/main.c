#include <stdio.h>

#define MAX_CHAR 21

typedef struct
{

    char *name[21];
    int score;

} playerData;

int main(void)
{

    FILE *data = fopen("data.txt", "w");
    if (data == NULL)
    {
        printf("Não foi possivel abrir o arquivo\n");
        return 1;
    }

    printf("Bem vindo ao cadastro de jogador\n");

    int wantExit = 0;
    while (!wantExit)
    {
        playerData currentData;

        scanf("%19s", &currentData.name);
        printf("Deseja sair? ");
        if (scanf("%d", &wantExit) != 1)
        {
            printf("Erro! Entrada invalida\n");
            return 2;
        }
    }

    return 0;
}

void verifyScanf(char dataType, void *variable)
{
    switch (dataType)
    {
    case 'd':

        if (scanf("%d", (int *)variable) != 1)
        {
            printf("Erro! Entrada invalida");
            return 2;
        }

        break;

    case 'c':

        if (scanf("%c", (char *)variable) != 1)
        {
            printf("Erro! Entrada invalida");
            return 2;
        }

        break;

    case 's':

        if (scanf("%s", (char *)variable) != 1)
        {
            printf("Erro! Entrada invalida");
            return 2;
        }

        break;

    default:

        printf("Entrada invalida!");

        break;
    }
}