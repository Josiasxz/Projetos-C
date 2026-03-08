// Correção do exercicio 8 - Comparação - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main(void)
{

    int numero1;
    printf("Digite um numero: ");
    scanf("%d", &numero1);

    int numero2;
    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);

    if (numero1 == numero2)
    {
        printf("O numero %i e o numero %i sao iguais\n", numero1, numero2);
    }
    else
    {
        printf("O numero %i e o numero %i nao sao iguais\n", numero1, numero2);
    }

    return 0;
}