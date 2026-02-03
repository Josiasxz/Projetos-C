// Solução do exercicio 6 - Media das notas - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    // Variaveis de media
    float nota1 = 6;
    float nota2 = 5;
    float nota3 = 8;

    // Verificação
    if (nota1 < 0 || nota2 < 0 || nota3 < 0)
    {
        printf("Insira uma nota valida");
        return 1;
    }

    // Faz a media dos valores e coloca na variavel `media`
    float media = (nota1 + nota2 + nota3) / 3;

    if (media < 6)   // --Se a media for menor que 6
    {
        printf("O aluno foi reprovado com uma nota de: %f\n", media); // --Aluno reprovado
    }
    else // --Se não
    {
        printf("O aluno foi aprovado com uma nota de: %f \n", media); // -- Aluno aprovado
    }

    return 0;
}