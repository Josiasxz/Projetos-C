#include <stdio.h>

#define MAX_CHAR 21

void verifyScanf(char dataType, void *variable);

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
    int option = 0;
    while (wantExit != 3)
    {

        printf("-------- MENU --------\n");
        printf("[1] - Adicionar um jogador\n");
        printf("[2] - Listar todos os jogadores adicionados\n");
        printf("[3] - Sair\n");
        printf("----------------------\n");

        while (option < 1 || option > 3)
        {
            printf("Selecione uma opção: ");
            verifyScanf('d', &option);
        }

        switch (option)
        {
            case 1:

                playerData currentData;

                printf("Digite um nome para o jogador: \n");
                
                break;

            default:

                break;
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

    case 'f':

        if (scanf("%f", (float *)variable) != 1)
        {
            printf("Erro! Entrada invalida");
            return 2;
        }

    case 'c':

        if (scanf("%c", (char *)variable) != 1)
        {
            printf("Erro! Entrada invalida");
            return 2;
        }

        break;

    case 's':

        if (scanf("%20s", (char *)variable) != 1)
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