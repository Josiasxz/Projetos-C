#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Input
    string text = get_string("Digite um texto: ");

    // Variaveis
    int nChar = 0;

    int nUpper = 0;
    int nLower = 0;
    int nDigit = 0;
    int nSpaces = 0;
    int nOtherChar = 0;

    // Executa e fornece o que é pedido
    while (text[nChar] != '\0')
    {
        // Acha quantas das maiusculas
        if (text[nChar] >= 'A' && text[nChar] <= 'Z')
        {
            nUpper++;
        }
        // Numero de letras minusculas
        else if (text[nChar] >= 'a' && text[nChar] <= 'z')
        {
            nLower++;
        }
        // Numero de espaços
        else if (text[nChar] == ' ')
        {
            nSpaces++;
        }
        else if (text[nChar] >= '0' && text[nChar] <= '9')
        {
            nDigit++;
        }
        else
        {
            nOtherChar++;
        }

        nChar++;
    }
    printf("O numero de letras maiusculas é: %i\n", nUpper);
    printf("O numero de letras minusculas é: %i\n", nLower);
    printf("O numero de digitos é: %i\n", nDigit);
    printf("O numero de espaços é: %i\n", nSpaces);
    printf("O numero de outros caracteres é: %i\n", nOtherChar);
}

