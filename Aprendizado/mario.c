#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int heig;
    do
    {
       heig = get_int("Height: ");
    }
    while (heig < 1 || heig > 8);

    for (int hor = heig; hor > 1; hor--)
    {
        
        for (int ver = 0; ver <= heig; ver++)
        {
           printf("#");
        }
        printf("\n");
    }
    return 0;
}