// Correção do exercicio 2 - Soma - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    int Valor1;
    printf("Insira o primeiro valor: ");
    scanf("%d", &Valor1);

    int Valor2;
    printf("Insira o segundo valor: ");
    scanf("%d", &Valor2);

    int Soma = Valor1 + Valor2;
    printf("A soma entre %i e %i e igual a: %i", Valor1, Valor2, Soma);
    
    return 0;
}