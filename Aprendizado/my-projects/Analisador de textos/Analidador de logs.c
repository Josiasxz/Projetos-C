#include <cs50.h>
#include <stdio.h>

int Qchar(string text);
int Qword (string text);
int bigestWord(string text);
int smallest_word (string text);
int word_tem_dig (string text);
int word_tem_splChar (string text);

int main(void)
{
    string textIn = get_string("Log: ");

    // Variaveis

    int charN = Qchar(textIn);
    int wordN = Qword(textIn);
    int big = bigestWord(textIn);
    int small = smallest_word (textIn);
    int wordDig = word_tem_dig (textIn);
    int wordSplChar = word_tem_splChar (textIn);
    //---------------------------------------------

    // Relatorio
    printf("O numero de caracteres é: %i\n", charN);
    printf("O numero de palavras é: %i\n", wordN);
    printf("A maior palavra é: %i\n", big);
    printf("A menor palavra é: %i\n", small);
    printf("O numero de palavras com digitos é: %i\n", wordDig);
    printf("O numero de palavras com caracteres especiais é: %i\n", wordSplChar);
}

int Qchar(string text)
{
    int c;

    for (c = 0; text[c] != '\0'; c++);
    return c;
}

int Qword (string text)
{
    int insideWord = 0;
    int wordN = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] == ' ')
        {
            insideWord = 0;
        }
        else if (!insideWord)
        {
            insideWord = 1;
            wordN++;
        }
    }

    return wordN;
}

int bigestWord(string text)
{
    int insideWord = 0;
    int current_length = 0;
    int final_length = 0;
    int pas_length = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        // Verifico se está dentro de uma palavra
        if (text[c] == ' ')
        {
            insideWord = 0;
        }
        else if (!insideWord)
        {
            insideWord = 1;
        }

        // Vai adicionar 1 ao tamanho da palavra até que esteja fora dela
        if (insideWord)
        {
            current_length++;
        }
        // Se não estiver dentro da palavra e...
        else if (!insideWord)
        {

            // Se o tamanho atual for maior que o tamanho passado
            if (current_length < pas_length)
            {
                // O tamanho atual passa valer o tamanho passado, mantendo assim o maior
                current_length = pas_length;
            }
            // Sempre atualiza a palavra passada para a palavra atual
            pas_length = current_length;
            final_length = current_length;
            current_length = 0;
        }
    }

    //Se não passar pelo loop caso haja somente uma palavra.
    if (final_length == 0)
    {
        final_length = current_length;
    }
    // Se a palavra estiver no final
    else if (current_length > final_length)
    {
        final_length = current_length;
    }

    return final_length;
}

int smallest_word (string text)
{
    int insideWord = 0;
    int current_length = 0;
    int final_length = 0;
    int pas_length = 2147483647;

    for (int c = 0; text[c] != '\0'; c++)
    {
        if (text[c] == ' ')
        {
            insideWord = 0;
        }
        else if (!insideWord)
        {
            insideWord = 1;

        }

        if (insideWord)
        {
            current_length++;
        }
        else if (!insideWord)
        {
            if (current_length > pas_length)
            {
                current_length = pas_length;
            }

            pas_length = current_length;
            final_length = current_length;
            current_length = 0;
        }
    }

    if (final_length == 0)
    {
        final_length = current_length;
    }
    else if (current_length < final_length)
    {
        final_length = current_length;
    }

    return final_length;
}

int word_tem_dig (string text)
{
    int insideWord = 0;
    int wordcomDig = 0;
    int digN = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        // Se o caracter selecionado for um espaço
        if (text[c] == ' ')
        {
            // Diz que está fora/ para entrar na palavra
            insideWord = 0;
            // Adiciona 1 as palavras caso o numero de digitos na palavra for maior que 0
            if (digN > 0)
            {
                wordcomDig++;
            }
            // Zera digN para a proxima palavra
            digN = 0;
        }
        // Se estiver entrando em uma palavra
        else if (!insideWord)
        {
            // insideWord passa a valer 1, siginifica que está dentro de uma palavra
            insideWord = 1;
        }

        if (insideWord)
        {
            if (text[c] >= '0' && text[c] <= '9')
            {
                digN++;
            }
        }

    }
    // Para palavras no fim, que não tem espaços no final.
    if (insideWord)
    {
        if (digN > 0)
        {
            wordcomDig++;
        }
    }
    return wordcomDig;
}

int word_tem_splChar (string text)
{
    int insideWord = 0;
    int wordcomSplChar = 0;
    int splCharN = 0;

    for (int c = 0; text[c] != '\0'; c++)
    {
        // Se o caracter selecionado for um espaço
        if (text[c] == ' ')
        {
            // Diz que está fora/ para entrar na palavra
            insideWord = 0;
            // Adiciona 1 as palavras caso o numero de digitos na palavra for maior que 0
            if (splCharN > 0)
            {
                wordcomSplChar++;
            }
            // Zera digN para a proxima palavra
            splCharN = 0;
        }
        // Se estiver entrando em uma palavra
        else if (!insideWord)
        {
            // insideWord passa a valer 1, siginifica que está dentro de uma palavra
            insideWord = 1;
        }

        if (insideWord)
        {
            if (!(text[c] >= '0' && text[c] <= '9') && !(text[c] >= 'A' && text[c] <= 'Z') && !(text[c] >= 'a' && text[c] <= 'z'))
            {
                splCharN++;
            }
        }

    }
    // Para palavras no fim, que não tem espaços no final.
    if (insideWord)
    {
        if (splCharN > 0)
        {
            wordcomSplChar++;
        }
    }
    return wordcomSplChar;
}



