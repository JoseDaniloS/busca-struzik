#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "busca_struzik.c"

int main(void) {
    int opcao = 0, linhas;
    char nomePesquisado[50];
    clock_t t;

    while (opcao != 4) {
        printf("\nOpcoes Disponiveis:\n1 - Cadastrar Aluno\n2 - Exibir Lista de Alunos Cadastrados\n3 - Buscar Aluno por Nome\n4 - Sair\n");
        opcao = validadorNumero();
        switch (opcao) {
        case 1:
            printf("Cadastrando Aluno...\n");
            cadastroAluno();
            system("cls");  
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
            while (i < linhas && fscanf(arquivo, " %49[^\t]\t%d\t%f\n", alunos[i].nome, &alunos[i].matricula, &alunos[i].media) == 3) {
                CaracterMaiusculo(alunos[i].nome);
                i++;
            }

            fclose(arquivo); 

            qsort(alunos, linhas, sizeof(Aluno), compararAlunos);

            printf("Informe um nome: ");
            scanf(" %49[^\n]", nomePesquisado);

            while (VerificaCaracter(nomePesquisado) == -1) {
                printf("Informe um nome novamente: ");
                scanf(" %49[^\n]", nomePesquisado);
            }

            CaracterMaiusculo(nomePesquisado);

            t = clock();
            int posicao = buscaExponencial(alunos, linhas, nomePesquisado);
            t = clock() - t;
            printf("Tempo de execucao: %lf", ((double)t) / ((CLOCKS_PER_SEC / 1000))); // conversão para double

            if (posicao != -1) {
                printf("\nPosicao: %d\nNome: %s\nMatricula: %d\nMedia: %.1f\n", posicao, alunos[posicao].nome, alunos[posicao].matricula, alunos[posicao].media);
            } else {
                printf("Posicao nao encontrada!\n");
            }

            free(alunos);
            break;
        case 4:
            printf("Encerrando o programa...\n");
            return 0;
        default:
            printf("Opcao Invalida\n");
            system("cls");
            break;
        }
    }

    return 0;
}

