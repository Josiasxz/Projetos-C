#include <stdio.h>

int main(void)
{
    FILE *file = fopen("file.txt", "r");
    FILE *newFile = fopen("newFile.txt", "w");

    if (newFile == NULL || file == NULL)
    {
        printf("Não foi possivel abrir o arquivo");
        return 1;
    }

    fprintf(newFile, "Seu nome: %s\n", "Josué");
    fprintf(newFile, "Sua idade: %i\n", 16);

    fclose(newFile);
    return 0;
}