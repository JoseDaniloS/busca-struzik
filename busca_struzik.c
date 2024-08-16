#include <string.h> //para utilização da função: strcmp
#include <stdio.h>
#include <ctype.h>

int buscaExponencial(char **vetor, int tamanho, char *valor)
{
    int i = 1;
    // Encontra o intervalo onde o valor pode estar
    while (i < tamanho && strcmp(vetor[i], valor) <= 0)
    {
        i *= 2;
    }
    int inicio = i / 2;
    int fim = i < tamanho ? i : tamanho; // Garante que o limite não ultrapasse o tamanho do vetor
    // Busca linear no intervalo
    for (int j = inicio; j < fim; j++)
    {
        if (strcmp(vetor[j], valor) == 0)
        {
            return j;
        }
    }
    return -1; // Se o valor não for encontrado, retorna -1
}

int main(void)
{
    char *vetor[] = {"ALICE", "BRUNO", "CLAUDIO", "DANILO", "EMERSON"};
    char valor[10];
    printf("Informe um nome: ");
    scanf(" %[^\n]", valor);
    for(int i = 0; i < strlen(valor); i++){
        valor[i] = toupper(valor[i]);
    }
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int posicao = buscaExponencial(vetor, tamanho, valor);

    if (posicao != -1)
    {
        printf("O nome esta na posiçao %d\n", posicao);
    }
    else
    {
        printf("Posição não encontrada!\n");
    }

    return 0;
}
