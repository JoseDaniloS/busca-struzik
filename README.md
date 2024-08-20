# Busca-struzik

## Busca Exponencial (também chamado busca a galope ou busca Struzik).<br>
É um algoritmo, criado por Jon Bentley e Andrew Chi-Chih Yao em 1976, para a buscar listas ordenadas ilimitadas.

## Tópicos

- [Sobre o algoritmo de busca exponencial](#sobre-o-algoritmo-de-busca-exponencial)
- [Como executar o código](#como-executar-o-código)
- [Busca binária](#busca-binária) 
- [Busca Exponencial](#busca-exponencial)
- [Complexidade da busca exponencial.](#complexidade-de-busca-exponencial)
- [Aplicabilidade](#aplicabilidade)
- [Referências](#referência) 

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
A função receberá um  ponteiro do tipo ```Aluno``` que aponta para uma struct, um ```int``` tamanho que receberá o número de alunos cadastrados(tamanho total do array) e um ponteiro de ```char```  que passará o nome pesquisado. Dentro da função iniciaremos uma variávei ```index``` com 1, pois o salto começa no primeiro índice do array. Pesquisa o intervalo dentro do qual o nome está incluído, aumentando o índice em potências de 2
Se este intervalo existir no array apliqua o algoritmo de Pesquisa Binária sobre ele, caso contrário, retorna -1.

## Complexidade de busca exponencial
### Tempo:
```
T(n) = C1 + C2 + C3 + C4(log n) + C5 (log n) + C6 +C7 + C8
T(n) = a + log n(b)
T(n) = a + log nb

1 -> T(n) = a + log nb //Remove Constantes de soma
2 -> T(n) = log nb //Remove Constantes Multiplicativas
3 -> T(n) = log n
T(n) = O(log n) //Notaçao Big O da Busca Exponencial 
```
### Espaço:
```
A complexidade de espaço é definida por O(1), pois espaço usado é constante, i = 1.
```
## Aplicabilidade
- Sua aplicabilidade se destaca principalmente em cenários onde o custo de acesso aos elementos é alto ou quando estamos lidando com listas muito grandes.
- Exemplo:<br> Lista de nomes ordenados<br> busca de nome por ou ID<br> busca de aluno por nome ou matricula.

## Referências
Algoritmo de Ordenação: Comparação de Desempenho | by Ismaelly Eyre | Medium
https://medium.com/@ismaelly_eyre_/algoritmos-de-ordenação-comparação-de-desempenho-e23806adab2f<br>
Quicksort - Wikipédia, a enciclopédia livre
https://pt.wikipedia.org/wiki/Quicksort<br>
Busca Exponencial - Wikipédia, a enciclopédia livre
https://pt.wikipedia.org/wiki/Busca_exponencial<br>
Andrew Chi-Chih Yao - Wikipédia, a enciclopédia livre
https://pt.wikipedia.org/wiki/Andrew_Chi-Chih_Yao<br>
Jon Bentley - Wikipédia, a enciclopédia livre
https://pt.wikipedia.org/wiki/Jon_Bentley


