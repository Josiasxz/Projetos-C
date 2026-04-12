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

int main (void)
{
    people peoples[100];
    int peoplesCount = 0;

    int option;
    selectOption(&option);

    while (option)
    {
        char namePeople[MAX_CHAR];
        int agePeople;

        switch (option)
        {
            case 1:

                if (peoplesCount >= 100)
                {
                    printf("Não é possivel adicionar mais pessoas!\n");
                    break;
                }

                if (input("Digite o nome da pessoa: ", "%s", namePeople) == false)
                    return INPUT_ERROR;

                if (input ("Digite a idade da pessoa: ", "%d", &agePeople) == false)
                    return INPUT_ERROR;

                peoples[peoplesCount] = createPeople(namePeople, agePeople);
                peoplesCount++;

                break;

            case 2: 

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
                break;
            
            default:
                return FALSE_OPTION;
        }

        if (option)
        {
            selectOption(&option);
        }
    }

    printf("Obrigado por usar o sistema!\n");
}

void showMenu (void)
{
    printf("---------- MENU ----------\n");
    printf("1 - Cadastrar pessoa\n");
    printf("2 - Mostrar pessoa\n");
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
    strcpy(newPeople.name, name);
    newPeople.age = age;
    return newPeople;
}