#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Variaveis principais, como valores e o resultado
    float v1 = get_float("Digite um valor: ");
    float v2 = get_float("Digite outro valor: ");
    float result = 0;

    // Pede para selecionar a operação desejada
    printf("Escolha algum dos valores para determinar sua operação\n");
    printf("1 - Multiplicar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n");

    int op = get_int("Selecione sua operação: ");

    //Cria um loop que verifica a operação realizada até que ela seja verdadeira
    while (op > 4 || op < 1)
    {
        op = get_int("Selecione uma operação valida: ");
    }
    //Verifica qual operação escolhida e faz o calculo com base na operação escolhida
    // Adição
    if (op == 1)
    {
        result = v1 + v2;
        printf("O resultado da multiplicação é %f\n", result);
    }
    //Subtração
    else if (op == 2)
    {
        result = v1 - v2;
        printf("O resultado da subtração é %f\n", result);
    }
    //Multiplicação
    else if (op == 3)
    {
        result = v1 * v2;
        printf("O resultado da multiplicação é %f\n", result);
    }
    //Divisão
    else
    {
        result = v1 / v2;
        printf("O resultado da divisão é %f\n", result);
    }
    //Finaliza o codigo
    return 0;
}

