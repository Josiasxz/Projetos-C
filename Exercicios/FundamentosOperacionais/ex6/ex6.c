// Correção do exercicio 6 - Celsius para Fahrenheit - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{

    float Celsius;
    printf("Digite uma temperatura em graus Celsius: ");
    scanf("%f", &Celsius);

    float Fahrenheit = Celsius * 1.8 + 32;

    printf("%.1f Graus Celsius e igual a %.1f Graus Fahrenheit.\n", Celsius, Fahrenheit);

    return 0;
}