#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct alunos {
    char nome[50];
    long int matricula;
    float media;
} Aluno;

// Função que vai contar quantas linhas existem no arquivo
int contarLinhas(FILE *arquivo) {
    char caracter;
    int linhas = 0;
    while ((caracter = fgetc(arquivo)) != EOF) {
        if (caracter == '\n') {
            linhas++;
        }
    }
    fseek(arquivo, 0, SEEK_SET);  // Volta o ponteiro para o início do arquivo
    return linhas;
}

// Função que aloca um vetor de alunos dinamicamente
Aluno *vetorAlunos(int linhas) {
    Aluno *alunos = (Aluno *)malloc(linhas * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Memoria Insuficiente!");
        exit(1);
    }
    return alunos;
}

// Função que converte todos os caracteres em maiúsculo
void CaracterMaiusculo(char *valor) {
    int tamanho = strlen(valor);
    for (int i = 0; i < tamanho; i++) {
        valor[i] = toupper(valor[i]);
    }
}

// Função que verifica se existe algum caractere inválido (considerando apenas letras e espaço)
int VerificaCaracter(char *valor) {
    int tamanho = strlen(valor);
    for (int i = 0; i < tamanho; i++) {
        if (!isalpha(valor[i]) && !isspace(valor[i])) {
            printf("Caracter invalido!\n");
            return -1;
        }
    }
    return 0;
}

// Função de comparação para qsort
int compararAlunos(const void *a, const void *b) {
    return strcmp(((Aluno *)a)->nome, ((Aluno *)b)->nome);
}

// Função para abrir o arquivo e verificar se foi aberto com sucesso
FILE *Verificacao(char *nome, char *modo) {
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo");
        exit(1);
    } else {
        printf("Arquivo aberto!\n");
    }
    return arquivo;
}

// Função de busca binária
int buscaBinaria(Aluno *alunos, int inicio, int fim, char *valor) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        int comparacao = strcmp(alunos[meio].nome, valor);

        if (comparacao == 0) {
            return meio; // Nome encontrado
        }
        if (comparacao < 0) {
            inicio = meio + 1; // Procurar na metade direita
        } else {
            fim = meio - 1; // Procurar na metade esquerda
        }
    }

    return -1; // Valor não encontrado
}

// Função de busca exponencial seguida de busca binária
int buscaExponencial(Aluno *alunos, int tamanho, char *valor) {
    int i = 1;
    // Encontra o intervalo onde o valor pode estar
    while (i < tamanho && strcmp(alunos[i].nome, valor) <= 0) {
        i *= 2; // Dobro o tamanho do intervalo
    }

    int inicio = i / 2;
    int fim = (i < tamanho) ? i : tamanho;

    return buscaBinaria(alunos, inicio, fim - 1, valor);
}

void cadastroAluno() {
    char nome[50];
    long int matricula;
    float media;

    FILE *arquivo = Verificacao("alunos.txt", "a+");

    printf("Informe o Nome:\n");
    scanf(" %[^\n]", nome);
    while(VerificaCaracter(nome) == -1){
        printf("Informe o Nome novamente:\n");
        scanf(" %[^\n]", nome);
    }

    printf("Informe a Matricula:\n");
    scanf("%ld", &matricula);
    while (matricula <= 0) {
        printf("Matrícula invalida! Informe Novamente:\n");
        scanf("%ld", &matricula);
    }

    printf("Informe a media (0.0 a 10.0):\n");
    while (1) {
        if (scanf("%f", &media) != 1) {
            printf("Média inválida! Informe Novamente:\n");
            while (getchar() != '\n'); // Limpa o buffer
        } else if (media < 0.0 || media > 10.0) {
            printf("Media invalida! Informe Novamente:\n");
        } else {
            break;
        }
    }

    fseek(arquivo, 0, SEEK_END); // Garante que o ponteiro está no final para adicionar novos registros
    fprintf(arquivo, "%s\t%ld\t%.1f\n", nome, matricula, media);
    printf("Aluno cadastrado com sucesso!\n");

    fclose(arquivo);
}

void exibirLista() {
    char nome[50];
    long int matricula;
    float media;

    FILE *arquivo = Verificacao("alunos.txt", "r");

    fseek(arquivo, 0, SEEK_SET); // Volta o ponteiro para o início do arquivo

    printf("Lista de Alunos Cadastrados:\n");
    while (fscanf(arquivo, " %49[^\t]\t%ld\t%f\n", nome, &matricula, &media) == 3) {
        printf("%s\t%ld\t%.1f\n", nome, matricula, media);
    }

    fclose(arquivo);
}

int main(void) {
    int opcao = 0, linhas;
    char nomePesquisado[50];

    while (opcao != 4) {
        printf("\nOpçoes Disponiveis:\n1 - Cadastrar Aluno\n2 - Exibir Lista de Alunos Cadastrados\n3 - Buscar Aluno por Nome\n4 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            printf("Cadastrando Aluno...\n");
            cadastroAluno();
            system("cls");  // Para Windows; use "clear" em sistemas Unix
            break;
        case 2:
            printf("Exibindo Lista...\n");
            exibirLista();
            break;
        case 3:
            printf("Buscando Aluno por Nome...\n");
            FILE *arquivo = Verificacao("alunos.txt", "r");

            linhas = contarLinhas(arquivo);
            Aluno *alunos = vetorAlunos(linhas);

            // Leitura dos dados
            int i = 0;
            while (i < linhas && fscanf(arquivo, " %49[^\t]\t%ld\t%f\n", alunos[i].nome, &alunos[i].matricula, &alunos[i].media) == 3) {
                CaracterMaiusculo(alunos[i].nome);
                i++;
            }

            fclose(arquivo); // Fechar o arquivo após a leitura

            qsort(alunos, linhas, sizeof(Aluno), compararAlunos);

            printf("Informe um nome: ");
            scanf(" %49[^\n]", nomePesquisado);

            while (VerificaCaracter(nomePesquisado) == -1) {
                printf("Informe um nome novamente: ");
                scanf(" %49[^\n]", nomePesquisado);
            }

            CaracterMaiusculo(nomePesquisado);

            int posicao = buscaExponencial(alunos, linhas, nomePesquisado);

            if (posicao != -1) {
                printf("\nPosicao: %d\nNome: %s\nMatricula: %ld\nMedia: %.1f\n", posicao, alunos[posicao].nome, alunos[posicao].matricula, alunos[posicao].media);
            } else {
                printf("Posicao nao encontrada!\n");
            }

            free(alunos);
            break;
        case 4:
            printf("Encerrando o programa...\n");
            
            return 0;
        default:
            printf("Opção Invalida!");
            system("cls");
            break;
        }
    }

    return 0;
}
