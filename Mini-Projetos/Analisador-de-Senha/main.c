#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 50

// Definição do tamanho das senhas
#define LOW_LENGTH 4
#define MEDIUM_LENGTH 8
#define HIGH_LENGTH 14

// soma de score baixo, medio, e alto
#define ADD_LOW 10
#define ADD_MEDIUM 15
#define ADD_HIGH 20

// Score total baixo, medio e alto

#define LOW_SCORE 33
#define MEDIUM_SCORE 66
#define HIGH_SCORE 100

typedef enum
{
    weakPassword,
    mediumPassword,
    strongPassword,
    divinePassword

}statusPassword;

char *inputPassword (void);
int passwordLen (char *password);
bool haveUppercase (char *password);
bool haveLowercase (char *password);
bool haveChar (char *password);
bool haveNum (char *password);
bool haveSimbols (char *password);
int scorePassword (char *password);


int main (void)
{
    char *password = inputPassword();

    int passwordScore =  scorePassword(password);

    if (passwordScore <= LOW_SCORE)
    {
        printf("Sua senha é fraca!\n");
    }
    else if (passwordScore <= MEDIUM_SCORE)
    {
        printf("Sua senha é media\n");
    }
    else
    {
        printf("Sua senha é forte\n");
    }

    return 0;
}

char *inputPassword (void)
{   
    char password[MAX_CHAR];
    fgets(password, MAX_CHAR, stdin);
    password[strcspn(password, "\n")] = '\0';

    return password;

}

int passwordLen (char *password)
{
    return strlen(password);
}

bool haveUppercase (char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
            return true;
    }

    return false;
}

bool haveLowercase (char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (islower(password[i]))
            return true;
    }

    return false;
}

bool haveChar (char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isalpha(password[i]))
            return true;
    }

    return false;
}

bool haveNum (char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isdigit(password[i]))
            return true;
    }

    return false;
}

bool haveSimbols (char *password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (!isalnum(password[i] && !isspace(password[i])))
            return true;
    }

    return false;
}

int scorePassword (char *password)
{
    int score = 0;

    if (passwordLen(password) <= LOW_LENGTH)
    {
        score += ADD_LOW;
    }
    else if (passwordLen(password) <= MEDIUM_LENGTH)
    {
        score += ADD_MEDIUM;
    }
    else
    {
        score += ADD_HIGH;
    }

    if (haveChar(password))
        score += ADD_MEDIUM;

    if (haveLowercase(password))
        score += ADD_MEDIUM;

    if (haveUppercase(password))
        score += ADD_HIGH;

    if (haveNum(password))
        score += ADD_LOW;

    if (haveSimbols(password))
        score += ADD_HIGH;

    return score;
}
