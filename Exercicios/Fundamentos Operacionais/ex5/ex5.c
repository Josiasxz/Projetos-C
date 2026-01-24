// Solução do exercicio 5 - Maior de 18 anos? - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    // Variavel da idade
    int idade = 0;

    // Verificação
    if (idade < 0) // -- Se for menor que 0
    {
        printf("Digite uma idade valida"); 
        return 1; // Retorna um erro
    }

    if (idade > 18) // Se for maior que 18
    {
        printf("É maior de 18 anos");
    }
    else // Se não for maior
    {
        printf("É maior de 18 anos");
    }

    return 0;
}