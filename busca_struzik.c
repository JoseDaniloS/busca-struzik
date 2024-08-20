#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "busca_struzik.h"

struct alunos
{
    char nome[50];
    int matricula;
    float media;
};

// Função que vai contar quantas linhas existem no arquivo
int contarLinhas(FILE *arquivo)
{
    char caracter;
    int linhas = 0;
    while ((caracter = fgetc(arquivo)) != EOF)
    {
        if (caracter == '\n')
        {
            linhas++;
        }
    }
    fseek(arquivo, 0, SEEK_SET); // Volta o ponteiro para o início do arquivo
    return linhas;
}

// Função que aloca um vetor de alunos dinamicamente
Aluno *vetorAlunos(int linhas)
{
    Aluno *alunos = (Aluno *)malloc(linhas * sizeof(Aluno));
    if (alunos == NULL)
    {
        printf("Memoria Insuficiente!");
        exit(1);
    }
    return alunos;
}

// Função que converte todos os caracteres em maiúsculo
void CaracterMaiusculo(char *valor)
{
    int tamanho = strlen(valor);
    for (int i = 0; i < tamanho; i++)
    {
        valor[i] = toupper(valor[i]);
    }
}

// Função que verifica se existe algum caractere inválido (considerando apenas buffers e espaço)
int VerificaCaracter(char *valor)
{
    int tamanho = strlen(valor);
    for (int i = 0; i < tamanho; i++)
    {
        if (!isalpha(valor[i]) && !isspace(valor[i]))
        {
            printf("Caracter invalido!\n");
            return -1;
        }
    }
    return 0;
}

// Função de comparação para qsort
int compararAlunos(const void *a, const void *b)
{
    return strcmp(((Aluno *)a)->nome, ((Aluno *)b)->nome);
}

// Função para abrir o arquivo e verificar se foi aberto com sucesso
FILE *Verificacao(char *nome, char *modo)
{
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo");
        exit(1);
    }
    else
    {
        printf("Arquivo aberto!\n");
    }
    return arquivo;
}

// Função de busca binária
int buscaBinaria(Aluno *alunos, int inicio, int fim, char *valor)
{
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        int comparacao = strcmp(alunos[meio].nome, valor);

        if (comparacao == 0)
        {
            return meio; // Nome encontrado
        }
        if (comparacao < 0)
        {
            inicio = meio + 1; // Procurar na metade direita
        }
        else
        {
            fim = meio - 1; // Procurar na metade esquerda
        }
    }

    return -1; // Valor não encontrado
}

// Função de busca exponencial seguida de busca binária
int buscaExponencial(Aluno *alunos, int tamanho, char *valor)
{
    int i = 1;
   
    while (i < tamanho && strcmp(alunos[i].nome, valor) <= 0) // Encontra o intervalo onde o valor pode estar
    {
        i *= 2; // Dobra o tamanho do intervalo
    }

    int inicio = i / 2;//Defino o início do intervalo
    int fim = (i < tamanho) ? i : tamanho;//Define o fim do intervalo

    return buscaBinaria(alunos, inicio, fim - 1, valor);
}

int validadorNumero()
{
    int numero;
    char buffer;
    int validador = -1;
    do
    {
        printf("Informe um Numero Valido:\n");
        validador = scanf("%d", &numero);
        do
        {
            buffer = getchar(); // limpar o buffer do teclado
        } while (buffer != '\n');
    } while (numero <= 0 || validador == 0);
    return numero;
}

float validadorMedia()
{
    float media;
    char buffer;
    int validador = -1;
    do
    {
        printf("Informe uma media valida:");
        validador = scanf("%f", &media);
        do
        {
            buffer = getchar(); // limpar o buffer do teclado
        } while (buffer != '\n');
    } while (validador == 0 || media < 0 || media > 10);
    return media;
}

void cadastroAluno()
{
    char nome[50];
    int matricula;
    float media;

    FILE *arquivo = Verificacao("alunos.txt", "a+");

    printf("Informe o Nome:\n");
    scanf(" %[^\n]", nome);
    while (VerificaCaracter(nome) == -1)
    {
        printf("Informe o Nome novamente:\n");
        scanf(" %[^\n]", nome);
    }
    
    printf("Informe a Matricula:\n");
    matricula = validadorNumero();

    media = validadorMedia();

    fprintf(arquivo, "%s\t%d\t%.1f\n", nome, matricula, media);
    printf("Aluno cadastrado com sucesso!\n");

    fclose(arquivo);
}

void exibirLista()
{
    char nome[50];
    int matricula;
    float media;

    FILE *arquivo = Verificacao("alunos.txt", "r");

    printf("Lista de Alunos Cadastrados:\n");
    while (fscanf(arquivo, " %49[^\t]\t%d\t%f\n", nome, &matricula, &media) == 3)
    {
        printf("%s\t%d\t%.1f\n", nome, matricula, media);
    }

    fclose(arquivo);
}

