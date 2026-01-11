#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Variavel não alteravel, carrega o valor base
    int value = get_int("Insira um digito: ");
    // Variavel de usavel, pode ser alteravel
    int valueU = value;
    // Valor do modulo
    int mod;
    // Numero de digitos do valor
    int numDig = 0;
    // Var para soma dos digitos
    int digSoma = 0;
    // Maior e menor dig
    int maiorD = 0, menorD = 9;
    while (valueU > 0)
    {
        // Calculo do modulo
        mod = valueU % 10;
        valueU /= 10;

        // Numero de digitos
        numDig++;

        // Soma de digitos
        digSoma += mod;

        // Maior digito
        maiorD = mod;
        if (maiorD < menorD)
        {
            maiorD = menorD;
        }
        if (menorD > maiorD)
        {
            menorD = maiorD;
        }
        menorD = mod;

    }
    printf("A quantidade de digitos do numero %i é igual a: %i\n", value, numDig);
    printf("A soma dos digitos do numero %i é igual a: %i\n", value, digSoma);
    printf("O maior digito do numero %i é: %i\n", value, maiorD);
    printf("O menor digito do numero %i é: %i\n", value, menorD);
    printf("FIM\n");
}
// Codigo acabou!!
