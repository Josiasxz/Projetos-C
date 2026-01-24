// Solução do exercicio 3 - Par ou Impar - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    // Variavel do numero
    int numero = 0;

    // Condicional que determina se o numero é par ou impar
    if (numero % 2 == 0) // -- Se o resto da divisão do numero por 2 for igual a 0
    {
        printf("O numero %i é par\n", numero); // -- O numero é par
    }
    else // -- Senão
    {
        printf("O numero %i é impar\n", numero); // -- O numero é impar
    }

    return 0;
}
