#include <stdio.h>
#include <cs50.h>

int main(void)
{
   float v1 = get_float ("Digite um valor: ");
   float v2 = get_float ("Digite outro valor: ");
   float result = 0;

    // Pede para selecionar a operação
   printf("Escolha algum dos valores para determinar sua operação\n");
   printf("1 - Multiplicar\n2 - Subtrair\n");

   int op = get_int ("Selecione sua operação: ");

   while (op > 2 || op < 1) {
      op = get_int ("Selecione uma operação valida: ");
   }

   if (op == 1){
      result = v1 + v2;
      printf("O resultado da multiplicação é %f\n", result);
   } else {
      result = v1 - v2;
      printf("O resultado da subtração é %f\n", result);
   }


   return 0;

}
