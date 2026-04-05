#include <stdio.h>
#include <string.h>

#define MAX_CHAR 100
#define MAX_VAR 50

typedef enum { false = 0, true = 1 } bool;

typedef struct
{
    char name[MAX_CHAR];
    bool value;
} var;

bool input(char *msg, char *format, void *var);
void getTokens(char *input, char *tokens[], char *sep, int *count);
char *removeQuotes(char *str);
bool getValue(const char *name, const var array[], int count);

int precedence(char *op)
{
    if (strcmp(op, "NOT") == 0) return 3;
    if (strcmp(op, "AND") == 0) return 2;
    if (strcmp(op, "OR") == 0) return 1;
    return 0;
}

bool isOperator(char *str)
{
    return strcmp(str, "AND") == 0 || strcmp(str, "OR") == 0 || strcmp(str, "NOT") == 0;
}

bool applyOp(char *op, bool a, bool b)
{
    if (strcmp(op, "AND") == 0) return a && b;
    if (strcmp(op, "OR") == 0) return a || b;
    return false;
}

bool evaluate(char *tokens[], int count, var vars[], int varCount)
{
    bool values[MAX_CHAR];
    char *ops[MAX_CHAR];
    int vTop = -1, oTop = -1;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(tokens[i], "(") == 0)
        {
            ops[++oTop] = tokens[i];
        }
        else if (strcmp(tokens[i], ")") == 0)
        {
            while (oTop >= 0 && strcmp(ops[oTop], "(") != 0)
            {
                char *op = ops[oTop--];

                if (strcmp(op, "NOT") == 0)
                {
                    bool val = values[vTop--];
                    values[++vTop] = !val;
                }
                else
                {
                    bool b = values[vTop--];
                    bool a = values[vTop--];
                    values[++vTop] = applyOp(op, a, b);
                }
            }
            oTop--;
        }
        else if (isOperator(tokens[i]))
        {
            while (oTop >= 0 && precedence(ops[oTop]) >= precedence(tokens[i]))
            {
                char *op = ops[oTop--];

                if (strcmp(op, "NOT") == 0)
                {
                    bool val = values[vTop--];
                    values[++vTop] = !val;
                }
                else
                {
                    bool b = values[vTop--];
                    bool a = values[vTop--];
                    values[++vTop] = applyOp(op, a, b);
                }
            }
            ops[++oTop] = tokens[i];
        }
        else
        {
            values[++vTop] = getValue(tokens[i], vars, varCount);
        }
    }

    while (oTop >= 0)
    {
        char *op = ops[oTop--];

        if (strcmp(op, "NOT") == 0)
        {
            bool val = values[vTop--];
            values[++vTop] = !val;
        }
        else
        {
            bool b = values[vTop--];
            bool a = values[vTop--];
            values[++vTop] = applyOp(op, a, b);
        }
    }

    return values[vTop];
}

int main(void)
{
    char str[MAX_CHAR];

    if (!input("Digite uma expressão: ", "%99[^\n]", str))
        return 1;

    char *tokens[MAX_CHAR];
    int tokensLen = 0;
    getTokens(str, tokens, ",", &tokensLen);

    char *expression = removeQuotes(tokens[0]);

    char *expTokens[MAX_CHAR];
    int expCount = 0;
    getTokens(expression, expTokens, " ", &expCount);

    var variables[MAX_VAR];
    int varCount = 0;

    for (int i = 1; i < tokensLen; i++)
    {
        char *pair[2];
        int pairCount = 0;

        getTokens(tokens[i], pair, "=", &pairCount);

        if (pairCount != 2)
            return 1;

        strcpy(variables[varCount].name, pair[0]);

        if (strcmp(pair[1], "true") == 0)
            variables[varCount].value = true;
        else if (strcmp(pair[1], "false") == 0)
            variables[varCount].value = false;
        else
            return 1;

        varCount++;
    }

    bool result = evaluate(expTokens, expCount, variables, varCount);

    printf("Resultado: %s\n", result ? "true" : "false");

    return 0;
}

bool input(char *msg, char *format, void *var)
{
    if (!var) return false;

    printf("%s", msg);
    return scanf(format, var) == 1;
}

void getTokens(char *input, char *tokens[], char *sep, int *count)
{
    *count = 0;
    char *token = strtok(input, sep);

    while (token)
    {
        tokens[(*count)++] = token;
        token = strtok(NULL, sep);
    }
}

char *removeQuotes(char *str)
{
    if (!str) return NULL;

    if (str[0] == '"') str++;

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '"')
        str[len - 1] = '\0';

    return str;
}

bool getValue(const char *name, const var array[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(name, array[i].name) == 0)
            return array[i].value;
    }

    return false;
}