// Solução do exercicio 9 - Um fatorial melhorado - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    int numero;
    int fatorial = 1;

    //Scanf()
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &numero);

    // Verificação
    while (numero < 0)
    {
        printf("Digite um numero valido!: ");
        scanf("%d", &numero);
    }
    
    for (int i = numero; i >= 1; i--)
    {
                fatorial *= i;
    }

    printf("O valor do fatorial de %i é: %i\n", numero, fatorial);

    return 0;
}