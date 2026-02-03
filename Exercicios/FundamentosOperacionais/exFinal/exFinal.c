// Solução do exercicio final - Uma calculadora - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    int valor1;
    int valor2;

    // Pede os valores ao usuario
    printf("Digite o primeiro valor: "); // Primeiro valor
    scanf("%d", &valor1);

    printf("Digite o segundo valor: "); // Segundo valor
    scanf("%d", &valor2);

    // Operação
    int operacao;

    // Pede a operação
    printf("Opcoes: \n1.Multiplicacao \n2.Subtracao \n3.Multiplicacao \n4.Divisao \nSelecione uma operacao: "); 
    scanf("%d", &operacao);
    
    //Verifica se a operação é valida
    while (operacao < 1 || operacao > 4)
    {
        printf("Digite uma operação valida!: ");
        scanf("%d", &operacao);
    }

    //Switch para realizar a operação

    switch (operacao)
    {
        // Adição
    case 1:
        printf("O resultado da adicao e: %i", valor1 + valor2);
        break;
        // Subtração
    case 2:
        printf("O resultado da subtracao e: %i", valor1 - valor2);
        break;
        // Multiplicação
    case 3:
        printf("O resultado da multiplicacao e: %i", valor1 * valor2);
        break;
        // Divisão
    case 4:
        printf("O resultado da multiplicacao e: %f", (float)valor1 / valor2);
        break;
    }

    return 0;
}