// Correção do exercicio 3 - Operações Basicas - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    int Valor1;
    printf("Insira o primeiro valor: ");
    scanf("%d", &Valor1);

    int Valor2;
    printf("Insira o primeiro valor: ");
    scanf("%d", &Valor2);

    printf("A soma entre %i e %i e igual a: %i\n", Valor1, Valor2, (Valor1 + Valor2));
    printf("A subtracao entre %i e %i e igual a: %i\n", Valor1, Valor2, (Valor1 - Valor2));
    printf("A multiplicacao entre %i e %i e igual a: %i\n", Valor1, Valor2, (Valor1 * Valor2));
    printf("A divisao entre %i e %i e igual a: %i\n", Valor1, Valor2, (Valor1 / Valor2));
    printf("O modulo entre %i e %i e igual a: %i\n", Valor1, Valor2, (Valor1 % Valor2));

    return 0;
}
