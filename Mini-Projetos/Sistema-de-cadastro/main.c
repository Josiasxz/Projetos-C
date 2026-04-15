#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR 50
#define INPUT_ERROR 1
#define FALSE_OPTION 2

typedef struct
{
    char name[MAX_CHAR];
    int age;
}people;

void showMenu (void);
bool input (const char *msg, const char *format, void *var);
bool selectOption (int *option);
people createPeople (char name[], int age);
void limparBuffer (void);

int main (void)
{
    people peoples[100];
    int peoplesCount = 0;

    int option;
    if (selectOption(&option) == false)
        return INPUT_ERROR;

    while (option)
    {
        char namePeople[MAX_CHAR];
        int agePeople;

        int oldestIndex = 0;

        switch (option)
        {
            case 1:

                printf("---------- Cadastrar pessoas ----------\n");
                if (peoplesCount >= 100)
                {
                    printf("Não é possivel cadastrar mais pessoas!\n");
                    break;
                }

                limparBuffer();
                printf("Digite seu nome: ");
                fgets(namePeople, MAX_CHAR, stdin);
                namePeople[strcspn(namePeople, "\n")] = '\0';

                if (input ("Digite a idade da pessoa: ", "%d", &agePeople) == false)
                    return INPUT_ERROR;

                peoples[peoplesCount] = createPeople(namePeople, agePeople);
                peoplesCount++;

                break;

            case 2: 
                printf("---------- Pessoas cadastradas ----------\n");
                if (peoplesCount <= 0)
                {
                    printf("Nenhuma pessoa foi encontrada!\n");
                    break;
                }

                for (int i = 0; i < peoplesCount; i++)
                {
                    printf("Pessoa %d:\n", i + 1);
                    printf("Nome: %s\n", peoples[i].name);
                    printf("Idade: %i\n\n", peoples[i].age);
                }

                break;
            
            case 3:
                
                printf("---------- Pessoa mais velha ----------\n");

                if (peoplesCount <= 0)
                {
                    printf("Nenhuma pessoa foi encontrada!\n");
                    break;
                }

                for (int i = 0; i < peoplesCount; i++)
                {
                    if (peoples[i].age > peoples[oldestIndex].age)
                        oldestIndex = i;
                }

                printf("A pessoa mais velha é: %s, com %i anos\n", peoples[oldestIndex].name, peoples[oldestIndex].age);

                break;

            case 0:
                break;
            
            default:
                return FALSE_OPTION;
        }

        if (option)
        {
            if (selectOption(&option) == false)
                return INPUT_ERROR;
        }
    }

    printf("Obrigado por usar o sistema!\n");
}

void showMenu (void)
{
    printf("---------- MENU ----------\n");
    printf("1 - Cadastrar pessoa\n");
    printf("2 - Mostrar pessoas\n");
    printf("3 - Mostrar pessoa mais velha\n");
    printf("0 - Sair\n");
    printf("--------------------------\n");
}

bool input (const char *msg, const char *format, void *var)
{
    if (var == NULL)
        return false;

    printf("%s", msg);

    if (scanf(format, var) != 1)
    {
        return false;
    }

    return true;
}

bool selectOption (int *option)
{
    if (option == NULL)
        return false;
    
    showMenu();

    if (input("Digite uma opção: ", "%d", option) == false)
        return false;

    while (*option < 0 || *option > 3)
    {
        if (input("Digite uma opção valida: ", "%d", option) == false)
        return false;
    }

    return true;
}

people createPeople (char name[], int age)
{
    people newPeople;
    strncpy(newPeople.name, name, MAX_CHAR);
    newPeople.name[MAX_CHAR - 1] = '\0';

    newPeople.age = age;
    return newPeople;
}

void limparBuffer (void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}