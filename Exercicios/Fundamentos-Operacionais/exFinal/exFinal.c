// Correção do exercicio final - Calculadora - "Qualquer erro contido no codigo me avise, sou iniciante como você."

#include <stdio.h>

int main(void)
{

    int querContinuar = 1;

    printf("BEM VINDO A CALCULADORA\n");

    while (querContinuar)
    {

        printf("Digite os valores para a operação embaixo: \n");

        float valor1;
        printf("Digite o primeiro valor: ");
        scanf("%f", &valor1);

        float valor2;
        printf("Digite o segundo valor: ");
        scanf("%f", &valor2);

        printf("Operações disponiveis: \n");
        printf("[1 - Adição]\n");
        printf("[2 - Subtração]\n");
        printf("[3 - Multiplicação]\n");
        printf("[4 - Divisão]\n");

        int operacao;
        printf("Selecione a operação: ");
        scanf("%d", &operacao);

        while (operacao < 1 || operacao > 4)
        {
            printf("Digite uma operação valida: ");
            scanf("%d", &operacao);
        }

        float resultado;

        switch (operacao)
        {
        case 1:

            resultado = valor1 + valor2;
            printf("%.2f mais %.2f é igual a: %.2f\n", valor1, valor2, resultado);
            break;

        case 2:

            resultado = valor1 - valor2;
            printf("%.2f menos %.2f é igual a: %.2f\n", valor1, valor2, resultado);
            break;

        case 3:

            resultado = valor1 * valor2;
            printf("%.2f vezes %.2f é igual a: %.2f\n", valor1, valor2, resultado);
            break;

        case 4:

            while (valor2 == 0)
            {
                printf("Impossivel dividir por 0!!!\n");
                printf("Digite um valor valido: ");
                scanf("%f", &valor2);
            }
            
            resultado = valor1 / valor2;
            printf("%.2f dividido por %.2f é igual a: %.2f\n", valor1, valor2, resultado);
            break;

        default:

            printf("Erro! Operação não encontrada!\n");
            return 1;
        }

        printf("Quer continuar? [1 - Sim] [0 - Não]: ");
        scanf("%d", &querContinuar);

        while (querContinuar < 0 || querContinuar > 1)
        {
            printf("Quer continuar? [1 - Sim] [0 - Não]: ");
            scanf("%d", &querContinuar);
        }
        
    }

    printf("Obrigado por usar a calculadora!\n");

    return 0;
}