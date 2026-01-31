#include <stdio.h>

int main(void)
{
    
    // Mapa
    for (int colum = 0; colum < 10; colum++)
    {
        if (colum == 0 || colum == 9)
        {
            printf("###############################################################\n");
        }
        else
        {
            printf("#                                                             #\n");
        }
    }

    return 0;
}