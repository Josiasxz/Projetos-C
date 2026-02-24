// Correção do exercicio 4 - Calcule a area de um triangulo - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main (void)
{
    float Base;
    printf("Insira a base do triangulo: ");
    scanf("%f", &Base);

    float Altura;
    printf("Insira a altura do triangulo: ");
    scanf("%f", &Altura);

    float Area = Base * Altura;
    printf("A area do triangulo e de: %.2f\n", Area);

    return 0;
    
}