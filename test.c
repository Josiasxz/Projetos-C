#include <stdio.h>

void OlaMundo(char text[10]);

int main(void)
{
    OlaMundo("escreva");
}

void OlaMundo(char text[10])
{
    printf("%s", text);
}