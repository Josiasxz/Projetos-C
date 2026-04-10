#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define INPUT_ERROR 1

bool input (const char *msg, const char *format, void *var);

int sum (int num1, int num2);
float calcAverage (int sum, int count);

int main (void)
{
    int currentGrade = 0;

    int sumGrade = 0;
    float averageGrade = 0;
    int countGrade = 0;
    int highestGrade = INT_MIN;
    int lowestGrade = INT_MAX;

    while (currentGrade >= 0)
    {
        if (input ("Digite uma nota [-1 para sair]: ", "%d", &currentGrade) == false)
            return INPUT_ERROR;

        if (currentGrade < 0)
            break;
        
        // Media
        sumGrade = sum(sumGrade, currentGrade);
        countGrade++;
        averageGrade = calcAverage(sumGrade, countGrade);

        // Maior nota
        if (currentGrade > highestGrade)
            highestGrade = currentGrade;

        // Menor nota
        if (currentGrade < lowestGrade)
            lowestGrade = currentGrade;
    }

    printf("A media das notas inseridas é: %.2f\n", averageGrade);
    printf("A maior nota é: %i\n", highestGrade);
    printf("A menor nota é: %i\n", lowestGrade);

    return 0;
}

bool input (const char *msg, const char *format, void *var)
{
    if (var == NULL)
        return false;
    
    printf("%s", msg);

    if (scanf(format, var) != 1)
        return false;

    return true;
}

int sum (int num1, int num2)
{
    return num1 + num2;
}

float calcAverage (int sum, int count)
{
    return (float)sum / count;
}