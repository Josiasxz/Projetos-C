// Solução do exercicio 4 - Positivo, negativo ou zero? - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    int numero = 0;

    
    if (numero < 0) // -- Se o numero for menor que zero.
    {
        printf("O numero %i é negativo!\n", numero);
    }
    else if (numero > 0) // -- Se o numero for maior que zero.
    {
        printf("O numero %i é positivo!\n", numero);
    }
    else // Se não for nenhum dos dois.
    {
        printf("É zero!\n");
    }

    return 0;
}