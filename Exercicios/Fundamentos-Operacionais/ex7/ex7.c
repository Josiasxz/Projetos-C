// Correção do exercicio 7 - Antecessor e Sucessor - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main(void)
{
    
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    int antecessorDoNumero = numero - 1;
    int sucessorDoNumero = numero + 1;

    printf("O antecessor do numero %i e %i, e o sucessor dele e o numero %i.\n", numero, antecessorDoNumero, sucessorDoNumero);

    return 0;
}
