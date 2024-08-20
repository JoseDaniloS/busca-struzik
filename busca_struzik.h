typedef struct alunos Aluno;

//Função que vai contar quantas linhas existem no arquivo e retornará o número de linhas
int contarLinhas(FILE *arquivo);

//Função que aloca um vetor de alunos dinamicamente e retorna o vetor de alunos
Aluno *vetorAlunos(int linhas);

// Função que converte todos os caracteres em maiúsculo
void CaracterMaiusculo(char *valor);

// Função que verifica se existe algum caractere inválido (considerando apenas letras e espaço)
int VerificaCaracter(char *valor);

// Função de comparação para qsort
int compararAlunos(const void *a, const void *b);

// Função para abrir o arquivo e verificar se foi aberto com sucesso
FILE *Verificacao(char *nome, char *modo);

// Função de busca binária
int buscaBinaria(Aluno *alunos, int inicio, int fim, char *valor);

// Função de busca exponencial e retorna função de busca binária
int buscaExponencial(Aluno *alunos, int tamanho, char *valor);

//Função para cadastrar dinamicamente uma estrura do tipo Aluno
// - Usa função Verificação para testar se um arquivo foi aberto da forma correta
// - Usa função VerificaCaracter para testar se o nome digitado não é um caracter e não é um espaço
void cadastroAluno();

//Função que exibe lista de nomes cadastradas no arquivo
void exibirLista();



