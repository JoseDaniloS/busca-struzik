#include <string.h> //para utilização da função: strcmp e strlen
#include <stdio.h>
#include <ctype.h>//para utilização da função: toupper e isalpha

int buscaExponencial(char **vetor, int tamanho, char * valor)
{
    int i = 1;
    // Encontra o intervalo onde o valor pode estar
    while (i < tamanho && strcmp(vetor[i], valor) <= 0)
    {
        i *= 2;//dobro o tamanho do intervalo
    }
    
    // Busca linear no intervalo
    for (int j = i / 2; j < i; j++){
        if (strcmp(vetor[j], valor) == 0){
            return j;//se o valor for encontrado retorna a posicao
        }
    }

    return -1; // Se o valor não for encontrado, retorna -1
}

void CaracterMaiusculo(char * valor){

    for(int i = 0; i < strlen(valor); i++){
        valor[i] = toupper(valor[i]);//transforma todos os caracteres em maiusculo
    }

}

int VerificaCaracter(char * valor){
    char c;
    for(int i = 0; i < strlen(valor); i++){
        c = valor[i];
        if(!isalpha(c)){//verifica se os caracteres da string são letras
            printf("Caracter Invalido!\n");
            return -1;
        }
    }
    return 0;
}

int main(void)
{
    char *vetor[] = {"ALICE", "BRUNO", "CLAUDIO", "DANILO", "EMERSON"};
    char valor[10];
    int v = 0;

    printf("Informe um nome: ");
    scanf(" %[^\n]", valor);

    do{
        v = VerificaCaracter(valor);
        if(v == -1){
            printf("Informe um nome novamente: ");
            scanf(" %[^\n]", valor);
        }
    }while(v == -1);

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

    return 0;
}
