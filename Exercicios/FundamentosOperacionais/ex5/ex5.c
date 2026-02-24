// Correção do exercicio 5 - Media de 3 notas - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    float Nota1;
    printf("Insira a primeira nota: ");
    scanf("%f", &Nota1);

    float Nota2;
    printf("Insira a segunda nota: ");
    scanf("%f", &Nota2);

    float Nota3;
    printf("Insira a terceira nota: ");
    scanf("%f", &Nota3);

    float Media = (Nota1 + Nota2 + Nota3) / 3;
    printf("A media das notas %.2f, %.2f e %.2f e igual a: %.2f", Nota1, Nota2, Nota3, Media);

    return 0;

}