// Correção do exercicio 9 - Menu Simples - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    
    int valor1;
    printf("Insira o primeiro valor: ");
    scanf("%d", &valor1);

    int valor2;
    printf("Insira o segundo valor: ");
    scanf("%d", &valor2);

    int opcao;
    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);

    int resultado;

    switch (opcao)
    {
    case 1:
        
        resultado = valor1 + valor2;
        printf("A soma de %i e %i e igual a %i\n", valor1, valor2, resultado);

        break;
    
    case 2:

        resultado = valor1 - valor2;
        printf("A subtracao de %i por %i e igual a %i\n", valor1, valor2, resultado);

        break;

    case 3:

        resultado = valor1 * valor2;
        printf("A multiplicacao de %i por %i e igual a %i\n", valor1, valor2, resultado);

        break;

    case 4:

        resultado = valor1 / valor2;
        printf("A divisão de %i por %i e igual a %i\n", valor1, valor2, resultado);

        break;

    default:

        printf("A operacao nao existe!!");
        return 1;

    }

    return 0;
}