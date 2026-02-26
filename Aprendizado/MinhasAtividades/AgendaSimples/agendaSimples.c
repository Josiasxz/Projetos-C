#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 51
#define MAX_CONTACTS 20
#define MAX_NUMBER 18
#define EXIT 4

typedef struct
{
    char name[MAX_CHAR];
    char number[MAX_NUMBER];

} Person;

void GetString(const char *printString, char *destino, int tamanhoMax);
int IsValidNumber(char *number);

int main(void)
{
    printf("----------------- BEM VINDO A AGENDA SIMPLES -----------------\n");

    Person personsList[MAX_CONTACTS];
    int listPosition = 0;

    int option = 0;

    while (option != EXIT)
    {
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar Contato\n");
        printf("4 - Sair\n");

        printf("Selecione uma opcao: ");
        scanf("%d", &option);

        while (option < 1 || option > 4)
        {
            printf("Digite uma opção valida: ");
            scanf("%d", &option);
        }
        
        getchar();

        switch (option)
        {
        case 1:

            do
            {
                GetString("Digite o nome: ", personsList[listPosition].name, MAX_CHAR);

                if (strlen(personsList[listPosition].name) >= MAX_CHAR - 1)
                    printf("Nome muito grande! Maximo permitido: 50 caracteres.\n");

            } while (strlen(personsList[listPosition].name) >= MAX_CHAR - 1);

            do
            {
                GetString("Digite o numero (16 digitos): ", personsList[listPosition].number, MAX_NUMBER);

                if (!IsValidNumber(personsList[listPosition].number))
                    printf("Numero invalido! Deve conter exatamente 16 digitos numericos.\n");

            } while (!IsValidNumber(personsList[listPosition].number));

            printf("\nContato adicionado com sucesso!\n");
            printf("Nome: %s\n", personsList[listPosition].name);
            printf("Numero: %s\n", personsList[listPosition].number);

            listPosition++;
            break;
        
        default:
            printf("Erro!!!");
            return 1;
            break;
        }
    }

    return 0;
}

void GetString(const char *printString, char *destino, int tamanhoMax)
{
    printf("%s", printString);
    fgets(destino, tamanhoMax, stdin);

    destino[strcspn(destino, "\n")] = '\0';
}

int IsValidNumber(char *number)
{
    if (strlen(number) != 17)
        return 0;

    if (number[0] != '+')
        return 0;

    if (number[3] != ' ' || number[6] != ' ')
        return 0;

    if (number[12] != '-')
        return 0;

    for (int i = 0; i < 17; i++)
    {
        if (i == 0 || i == 3 || i == 6 || i == 12)
            continue;

        if (!isdigit(number[i]))
            return 0;
    }

    return 1;
}