#include <stdio.h>

int main (void)
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    printf("Digite 3 numeros: ");
    if (scanf("%d %d %d", &num1, &num2, &num3) != 3)
    {
        return 1;
    }

    int maior = num1;
    int menor = num1;
    int meio = num1;

    if (num2 > maior)
        maior = num2;

    if (num2 < menor)
        menor = num2;
    

    if (num3 > maior)
    {
        maior = num3;
    }
    if (num3 < menor)
    {
        menor = num3;
    }

    meio = num1 + num2 + num3 - maior - menor;
    
    printf("O maior é: %i", maior);
    printf("O menor é: %i", menor);
    printf("O do meio é: %i", meio);

    return 0;

}