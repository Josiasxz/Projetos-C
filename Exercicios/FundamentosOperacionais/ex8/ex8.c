// Solução do exercicio 8 - Calcule o fatorial - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main(void)
{
    // Entrada
    int numero = 5;
    // Começa em 1 pois 1 é o elemento neutro da matematica (multiplicar por 1 não altera o valor original)
    int fatorial = 1;

    // Verificação
    if (numero < 0)
    {
        printf("Digite um valor valido!\n");
    }
    // Realiza o calculo
    else
    {
        for (int i = numero; i >= 1; i--)
        {
                fatorial *= i;
        }
    }
    
    printf("O valor do fatorial de %i é: %i\n", numero, fatorial);

    return 0;
}