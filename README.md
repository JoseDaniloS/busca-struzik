# Busca-struzik

## Busca Exponencial (também chamado busca a galope ou busca Struzik).<br>
É um algoritmo, criado por Jon Bentley e Andrew Chi-Chih Yao em 1976, para a busca listas ordenadas ilimitadas.

## Tópicos

- Sobre o algoritmo de busca exponencial
- Como executar o código
- Busca binária 
- Busca Exponencial
- Complexidade da busca exponencial.
- Aplicabilidade 
- Referências 

## Sobre o algoritmo de busca exponencial<br>

- A pesquisa exponencial permite pesquisar em uma lista classificada e ilimitada por um valor de entrada especificado. O algoritmo consiste em duas etapas, por isso que a busca exponencial é considerada um algoritmo híbrido. A primeira fase visa buscar um intervalo de um array de entrada no qual assume-se que o elemento desejado deve estar presente e, estando o elemento no intervalo, aplica-se a segunda etapa, que seria realizar uma busca binária nesse intervalo pequeno. 

## Como executar o código<br>
- Para a execução do código é preciso abrir o terminal e digitar ./main

## Busca binária<br>
- Para utilizar a pesquisa exponencial é preciso ter conhecimento da busca binária (ou busca sequencial/linear, mas esta, em comparação com a binária é menos eficiente). No código implementamos uma função de busca binária:

```
int buscaBinaria(Aluno *alunos, int inicio, int fim, char *valor);
```
## Busca exponencial<br>

```
int buscaExponencial(Aluno *alunos, int tamanho, char *valor);
```





