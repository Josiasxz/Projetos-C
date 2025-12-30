#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void)
{
    // Variaveis
    float v1 = 0;
    float v2 = 0;
    // Potencia e Raiz
    double b = 0;
    double e_i = 0;
    // Resultado
    float result = 0;

    // Pede para selecionar a operação desejada
    printf("Escolha algum dos valores para determinar sua operação\n");
    printf("1 - Multiplicar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n5 - Potencia\n6 - Raiz\n");

    // Verifica se a operação selecionada e valida
    int op = get_int("Selecione sua operação: ");
    while (op > 6 || op < 1)
    {
        op = get_int("Selecione uma operação valida: ");
    }


    // Verifica qual operação selecionada e qual tipo de calculo deve ser tomado
    if (op >= 1 && op <= 4)
    {
        v1 = get_float("Insira o primeiro valor: ");
        v2 = get_float ("Insira o segundo valor: ");
    }
    else if (op == 5)
    {
        b = get_float ("Insira o valor ra potencia: ");
        e_i = get_int("Insira o expoente do potencia:  ");
    }
    else
    {
        b = get_float ("Insira o valor da raiz: ");
        e_i = get_int ("Insira o indice da raiz: ");
    }


    //Verifica qual operação escolhida e faz o calculo com base na operação escolhida
    // Adição

    if (op == 1)
    {
        result = v1 + v2;
        printf("O resultado da adição de %f mais %f é %f\n", v1, v2, result);
    }
    //Subtração
    else if (op == 2)
    {
        result = v1 - v2;
        printf("O resultado da subtração de %f menos %f é %f\n", v1, v2, result);
    }
    //Multiplicação
    else if (op == 3)
    {
        result = v1 * v2;
        printf("O resultado da multiplicação de %f vezes %f é %f\n", v1, v2, result);
    }
    //Divisão
    else if (op == 4)
    {
        result = v1 / v2;
        printf("O resultado da divisão de %f por %f é %f\n",v1, v2, result);
    }
    else if (op == 5)
    {
        result = pow(b, e_i);
        printf("O resultado da potencia de %lf elevado a %lf é %lf\n", b, e_i, result);
    }
    else
    {
        result = pow(b, 1.0 / e_i);
        printf("O resultado da raiz de %lf com indice de %lf é de %lf\n", b, e_i, result);
    }
    //Finaliza o codigo
    return 0;
}

