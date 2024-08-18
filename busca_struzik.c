#include <string.h> //para utilização da função: strcmp e strlen
#include <stdio.h>
#include <ctype.h> //para utilização da função: toupper e isalpha
#include <stdlib.h>

// int buscaExponencial(char **vetor, int tamanho, char *valor);

// void CaracterMaiusculo(char *valor);

int VerificaCaracter(char *valor);

void cadastraNome(char **vetor, int *tamanho, int *capacidade);

int main(void)
{
    char **vetor = (char **)malloc(10 * sizeof(char *));
    if (vetor == NULL)
    {
        printf("erro ao alocar.");
        exit(1);
    }

    int opcao;
    int tamanho = 0;
    int capacidade = 10;

    printf("O que deseja fazer:\n[1] - cadastro\n2 - busca\n->");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        cadastraNome(vetor, &tamanho, &capacidade);
        break;

    default:
        printf("erro");
        break;
    }
}

CaracterMaiusculo(valor);

int tamanho = sizeof(vetor) / sizeof(vetor[0]);
int posicao = buscaExponencial(vetor, tamanho, valor);

if (posicao != -1)
{
    printf("O nome esta na posicao %d\n", posicao);
}
else
{
    printf("Posicao nao encontrada!\n");
}

void cadastraNome(char **vetor, int *tamanho, int *capacidade)
{
    int v = 0;
    char valor[50];

    while (1)
    {
        printf("Informe um nome ou aperte [0] para sair: ");
        scanf(" %[^\n]", valor);

        if (strcmp(valor, "0") == 0)
        {
            break;
        }
        if (*tamanho >= *capacidade)
        {
            *capacidade *= 2;
            vetor = (char **)realloc(vetor, *capacidade * sizeof(char *));
            if (vetor == NULL)
            {
                printf("erro na alocação. Programa será fechado.");
                exit(1);
            }
        }

        vetor[*tamanho] = (char *)malloc(strlen(valor) + 1);
        if (vetor[*tamanho] == NULL)
        {
            printf("erro ao alocar.");
            exit(1);
        }
        strcpy(vetor[*tamanho], valor);
        (*tamanho)++;

        do
        {
            v = VerificaCaracter(valor);
            if (v == -1)
            {
                printf("Informe um nome novamente: ");
                scanf(" %[^\n]", valor);
            }
        } while (v == -1);
    }
}

int buscaExponencial(char **vetor, int tamanho, char *valor)
{
    int i = 1;
    // Encontra o intervalo onde o valor pode estar
    while (i < tamanho && strcmp(vetor[i], valor) <= 0)
    {
        i *= 2; // dobro o tamanho do intervalo
    }

    // Busca linear no intervalo
    for (int j = i / 2; j < i; j++)
    {
        if (strcmp(vetor[j], valor) == 0)
        {
            return j; // se o valor for encontrado retorna a posicao
        }
    }

    return -1; // Se o valor não for encontrado, retorna -1
}

void CaracterMaiusculo(char *valor)
{

    for (int i = 0; i < strlen(valor); i++)
    {
        valor[i] = toupper(valor[i]); // transforma todos os caracteres em maiusculo
    }
}

int VerificaCaracter(char *valor)
{
    char c;
    for (int i = 0; i < strlen(valor); i++)
    {
        c = valor[i];
        if (!isalpha(c))
        { // verifica se os caracteres da string são letras
            printf("Caracter Invalido!\n");
            return -1;
        }
    }
    return 0;
}