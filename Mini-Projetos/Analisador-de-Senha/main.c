#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 50

char *inputPassword (void);
int passwordLen (char *password);
bool haveUppercase (char *password);
bool haveLowercase (char *password);
bool haveChar (char *password);
bool haveNum (char *password);
bool haveSimbols (char *password);


int main (void)
{
    char *password = inputPassword();
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
