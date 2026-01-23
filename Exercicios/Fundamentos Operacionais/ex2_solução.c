// Correção do exercicio 2, transformar celsius em fahrenheit:

#include <stdio.h>

int main(void)
{
    float celsius = 0;

    float fahrenheit = (celsius * 1.8) + 32;

    printf("Os graus celsius em fahrenheit e: %f\n", fahrenheit);

    // OU

    printf("Os graus celsius em fahrenheit e: %f\n", (celsius * 1.8 + 32));

    return 0;
}