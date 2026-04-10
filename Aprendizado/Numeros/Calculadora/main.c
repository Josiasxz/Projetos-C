#include <stdio.h>
#include <stdbool.h>

#define INPUT_ERROR 1
#define OPERATION_ERROR 2

void showMenu (void);
bool input (char *msg, char *format, void *var);
bool selectOptions (int *options);
bool inputValues (char *format, void *var1, void *var2);

// Math functions
float sum (float valor1, float valor2);
float sub (float valor1, float valor2);
float plus (float valor1, float valor2);
float div (float valor1, float valor2);

int main (void)
{

    int options = 0;

    if (selectOptions(&options) == false)
        return INPUT_ERROR;

    float num1 = 0, num2 = 0, result = 0;

    if (inputValues("%f", &num1, &num2) == false)
        return INPUT_ERROR;
    
    while (options)
    {
        switch (options)
        {
            case 1:
                result = sum(num1, num2);  
                printf("O resultado da soma é: %2.f\n", result);
                break;

            case 2:
                result = sub(num1, num2);
                printf("O resultado da subtração é: %2.f\n", result);
                break;
            
            case 3:
                result = plus(num1, num2);
                printf("O resultado da multiplicação é: %2.f\n", result);
                break;
            
            case 4:
                result = div(num1, num2);
                printf("O resultado da divisão é: %2.f\n", result);
                break;
            
            default:
                return OPERATION_ERROR;
        }
        
        if (selectOptions(&options) == false)
            return INPUT_ERROR;   

        if (inputValues("%f", &num1, &num2) == false)
        return INPUT_ERROR;
    }

    return 0;
}

void showMenu (void)
{
    printf("---------- MENU ----------\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("0 - Sair\n");
}

bool input (char *msg, char *format, void *var)
{
    if (var == NULL)
        return false;

    printf("%s", msg);

    if (scanf(format, var) != 1)
        return false;

    return true;
}

bool selectOptions (int *options)
{ 
    if (options == NULL)
        return false;

    showMenu();

    if (input("Selecione uma opção: ", "%d", options) == false)
        return false;

    while (*options < 0 || *options > 4)
    {
        if (input("Digite uma opção valida: ", "%d", options) == false)
            return false;
    }

    return true;

}

bool inputValues (char *format, void *var1, void *var2)
{
    if (var1 == NULL || var2 == NULL)
        return false;

    if (input("Digite o primeiro valor: ", format, var1) == false)
        return false;
    
    if (input("Digite o segundo valor: ", format, var2) == false)
        return false;

    return true;
    
}
// FUNÇÕES MATEMATICAS

float sum (float valor1, float valor2)
{
    return valor1 + valor2;
}

float sub (float valor1, float valor2)
{
    return valor1 - valor2;
}

float plus (float valor1, float valor2)
{
    return valor1 * valor2;
}

float div (float valor1, float valor2)
{
    return valor1 / valor2;
}
