#include <cs50.h>
#include <stdio.h>

typedef struct
{
    int start;
    int length;
} WordInfo;

void verify(string text);
int nChar(string text);
int countUpper(string text);
int countLower(string text);
int countDig (string text);
int countSpace (string text);
int countSplChar(string text);
WordInfo longest_word(string text);
WordInfo smallest_word(string text);


int main(void)
{
    string textIn = get_string("Digite seu texto: ");

    // Verificação do texto
    verify(textIn);
    //---------------

    // Variaveis
    int charN = nChar(textIn);
    int upperN = countUpper(textIn);
    int lowerN = countLower(textIn);
    int digN = countDig(textIn);
    int spaceN = countSpace(textIn);
    int specialChar = countSplChar(textIn);

    int wordsN;
    WordInfo big = longest_word(textIn);
    WordInfo small = smallest_word(textIn);

    int frasesN;

    //------------------

    // Relatorio
    printf("Total de caracteres: %i\n", charN);
    printf("Total de letras maiusculas: %i\n", upperN);
    printf("Total de letras minusculas: %i\n", lowerN);
    printf("Total de digitos é: %i\n", digN);
    printf("Total de espaços é: %i\n", spaceN);
    printf("Total de caracteres especiais é: %i\n", specialChar);

    printf("Maior palavra: ");
    for (int i = 0; i < big.length; i++)
    {
        printf("%c", textIn[big.start + i]);
    }
    printf(" (%i letras)\n", big.length);

    printf("Menor palavra: ");
    for (int i = 0; i < small.length; i++)
    {
        printf("%c", textIn[small.start + i]);
    }
    printf(" (%i letras)\n", small.length);

}


// Verificação
void verify(string text)
{
    //Numero de espaços
    int spaceN = countSpace(text);

    //Verificação do numero de caracteres
    int c;
    for (c = 0; text[c] != '\0'; c++);

    // Loop que realiza a verificação
    while (text[0] == '\0' || spaceN == c)
    {
        text = get_string("Digite um texto valido: ");

        // Atualiza as variaveis com o texto inserido
        for (c = 0; text[c] != '\0'; c++);
        spaceN = countSpace(text);
    }
}

// Propiedades de todo o texto

// Numero de caracteres
int nChar(string text)
{
    int charN;
    for (charN = 0; text[charN] != '\0'; charN++);

    return charN;
}

// Numero de Maiusculas
int countUpper(string text)
{
    int upperC = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] >= 'A' && text[c] <= 'Z')
        {
            upperC++;
        }
    }

    return upperC;
}

// Numero de Minusculas
int countLower(string text)
{
    int lowerC = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] >= 'a' && text[c] <= 'z')
        {
            lowerC++;
        }
    }

    return lowerC;
}

// Numero de Digitos
int countDig (string text)
{
    int digN = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] >= '0' && text[c] <= '9')
        {
            digN++;
        }

    }

    return digN;
}

// Numero de Espaços
int countSpace (string text)
{
    int spaceC = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] == ' ')
        {
            spaceC++;
        }
    }

    return spaceC;
}

// Numero de Caracteres Especiais
int countSplChar(string text)
{
    int splCharN = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (!(text[c] >= 'A' && text[c] <= 'Z') && !(text[c] >= 'a' && text[c] <= 'z') && !(text[c] >= '0' && text[c] <= '9') && !(text[c] == ' '))
        {
            splCharN++;
        }
    }

    return splCharN;
}
//------------------------------------------------------------------------------------------------------------------------------------

// Palavras e frases

// Conta o numero de palavras
int countWords (string text)
{
    int wordsN = 0;
    int isInsideWord = 0;
    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] == ' ')
        {
            isInsideWord = 0;
        }
        else if (!isInsideWord)
        {
            isInsideWord = 1;
            wordsN++;
        }
    }

    return wordsN;
}

// Conta o numero de frases
int countFras (string text)
{
    int frasN = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] == '.' || text[c] == '?' || text[c] == '!')
        {
            frasN++;
        }
    }
    return frasN;
}

WordInfo longest_word(string text)
{
    WordInfo result = {0, 0};

    int i = 0;
    int current_start = 0;
    int current_length = 0;
    int inside_word = 0;

    while (text[i] != '\0')
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') ||
            (text[i] >= 'a' && text[i] <= 'z'))
        {
            if (!inside_word)
            {
                inside_word = 1;
                current_start = i;
                current_length = 0;
            }
            current_length++;
        }
        else
        {
            if (inside_word && current_length > result.length)
            {
                result.start = current_start;
                result.length = current_length;
            }
            inside_word = 0;
        }
        i++;
    }

    // Caso a maior palavra esteja no final
    if (inside_word && current_length > result.length)
    {
        result.start = current_start;
        result.length = current_length;
    }

    return result;
}

WordInfo smallest_word(string text)
{
    WordInfo result = {0, 100000}; // começa "gigante"

    int i = 0;
    int current_start = 0;
    int current_length = 0;
    int inside_word = 0;

    while (text[i] != '\0')
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') ||
            (text[i] >= 'a' && text[i] <= 'z'))
        {
            if (!inside_word)
            {
                inside_word = 1;
                current_start = i;
                current_length = 0;
            }
            current_length++;
        }
        else
        {
            if (inside_word && current_length < result.length)
            {
                result.start = current_start;
                result.length = current_length;
            }
            inside_word = 0;
        }
        i++;
    }

    if (inside_word && current_length < result.length)
    {
        result.start = current_start;
        result.length = current_length;
    }

    return result;
}
