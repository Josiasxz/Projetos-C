// Correção Exercicio 2 - Operadores basicos - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main(void)
{
    float numero_1 = 6;
    float numero_2 = 4;

    // Não precisa conter isso, mas fica mais completo tendo
    if (numero_1 == 0 && numero_2 == 0)
    {
        printf("Insira um valor valido!");
        return 1;
    }

    printf("A soma entre os dois valores e: %f\n", numero_1 + numero_2);
    printf("A subtração entre os dois valores e: %f\n", numero_1 - numero_2);
    printf("A multiplicação entre os dois valores e: %f\n", numero_1 * numero_2);
    printf("A divisão entre os dois valores e: %f\n", numero_1 / numero_2);

    // Há outras formas de fazer isso, umas mais complexas e outras mais simples, mas se o resultado final não contem erro, pode considerar feito, vou incluir abaixo uma forma que eu mesmo faria isso a um tempo atras

    float soma = numero_1 + numero_2;
    float subtracao = numero_1 - numero_2;
    float multiplicacao = numero_1 * numero_2;
    float divisao = numero_1 / numero_2;

    printf("\n");
    printf("Forma que eu faria isso antes: \n");
    printf("\n");

    printf("A soma entre os dois valores e: %f\n", soma);
    printf("A subtração entre os dois valores e: %f\n", subtracao);
    printf("A multiplicação entre os dois valores e: %f\n", multiplicacao);
    printf("A divisão entre os dois valores e: %f\n", divisao);

    return 0;
}