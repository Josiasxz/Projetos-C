// ------------------ Analisador de senhas ----------------------

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Pede a senha do usuario e guarda ela
    string password = get_string("Digite sua senha: ");

    // Variaveis
    int charN = 0;
    int upperL = 0;
    int lowerL = 0;
    int digN = 0;
    int specialChar = 0;
    int hasSpaces = 0;


    while (password[charN] != '\0')
    {
        // Verificação se tem espaços
        if (password[charN] == ' ')
        {
            hasSpaces++;
        }
        // Letras maiusculas
        else if (password[charN] >= 'A' && password[charN] <= 'Z')
        {
            upperL++;
        }
        // Letras minusculas
        else if (password[charN] >= 'a' && password[charN] <= 'z')
        {
            lowerL++;
        }
        // Digitos
        else if (password[charN] >= '0' && password[charN] <= '9')
        {
            digN++;
        }
        // Caracteres Especiais
        else
        {
            specialChar++;
        }
        // Adiciona o incremento
        charN++;
    }

    // Validação de senha
    if (charN <= 0 || hasSpaces > 0)
    {
         password = get_string("Digite uma senha valida: ");
    }

    // Senha forte ou senha fraca
    if (charN >= 8 && upperL >= 1 && lowerL >= 1 && digN >= 1 && specialChar >= 1)
    {
        printf("Sua senha é forte\n");
    }
    else
    {
        printf("SUa senha é fraca\n");
    }

    return 0;
}
