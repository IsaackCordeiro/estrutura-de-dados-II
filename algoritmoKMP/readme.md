# Algoritmo Knuth-Morris-Pratt (KMP)
---

- O algoritmo Knuth-Morris-Pratt (KMP) é um algoritmo de busca de padrões em strings que foi desenvolvido por Donald Knuth, Vaughan Pratt e James Morris em 1977. O KMP é um algoritmo linear, ou seja, seu tempo de execução é proporcional ao tamanho da string de entrada.

<p>

- O KMP busca por um padrão em uma string usando um vetor chamado de tabela de falha ou vetor de prefixo, que contém informações sobre o padrão. A tabela de falha é construída antes de realizar a busca e utiliza o próprio padrão para identificar onde um eventual erro ocorreu na busca.

O Algoritmo consiste em duas fases:

1. Construção da tabela de falha
2. Busca do padrão

<p>

A ideia geral é:
- Quando aparece uma diferença (conflito), a palavra tem em si a informação necessária para determinar onde começar a próxima comparação (isso evita retroceder pelos caracteres já conhecidos) <p>

## Pre-processamento
Basicamente é procurar o maior prefixo que também é sufixo. 

Exemplo: 

**ABC**D**ABC**

Prefixos: A, AB, <u>ABC</u>, ABCD, ABCDA...
Sufixos: C, BC, <u>ABC</u>, DABC, CDABC...

ABC é o maior prefixo que também é sufixo.

É preciso analisar também, a parte do padrão que se repete e inserir no vetor preProcess a posição equivalente.

Exemplo:

| | | | | | | | |
| --- | --- | --- | --- | --- | --- | --- | --- |
**i** | 0 | 1 | 2 | 3 | 4 | 5 | 6              
**padrão** | A | B | C | D | A | B | C       
**preProcess** | -1 | -1 | -1 | -1 | 0 | 1 | 2   

Observe o que foi descrito acima, e veja que onde se repetiu foi inserido no preProcess os mesmos indíces. Isso vai ajudar a não fazer comparações desnecessárias na hora da busca.

Mais exemplos:

| | | | | | | | | | | |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
**i** | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9            
**padrão**  | A | B | C | D | A | B | E | A | B | F |   
**preProcess** | -1 | -1 | -1 | -1 | 0 | 1 | -1 | 0 | 1 | -1  | 

| | | | | | | | | | | | |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
**i** | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10              
**padrão** | A | B | C | D | E | A | B | F | A| B | C        
**preProcess** | -1 | -1 | -1 | -1 | -1 | 0 | 1| -1 | 0 | 1 | 2     

| | | | | | | | | | | |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
**i** | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9               
**padrão** | A | A | B | C | A | D | A | A | B | E         
**preProcess** | -1 | 0 | -1 | -1 | 0 | -1 | 0 | 1 | 2 | -1     

| | | | | | | | | | |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | 
**i** | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8              
**padrão** | A | A | A | A | B | A | A | C | D        
**preProcess** | -1 | 0 | 1 | 2 | -1 | 0 | 1 | -1 | -1

<br>

#### Função de Pré-processamento em linguagem C

~~~C
int *preProcessamentoKMP(char *padrao){
    int i, j = -1;
    
    int *preProcess = malloc(M * sizeof(int)); 

    preProcess[0] = j;

    for(i = 1 ; i < M ; i++){
        while (j > -1 && padrao[j+1] != padrao[i]){
            j = preProcess[j];
        }
        if(padrao[i] == padrao[j+1]){
            j++;
        }
        preProcess[i] = j;
        
    }
    for(int x = 0; x < M ; x++){
        printf("%d\n", preProcess[x]);
    }

    return preProcess;

}
~~~

## Busca KMP

* Após o pré-processamento, é necessário fazer a busca de fato. 
* Para isso, é comparado o Padrão com o Texto posição por posição e caso a posição do Padrão for diferente da posição do Texto, é utilizado o vetor preProcess para dar shift(pular) e evitar comparações repetidas desnecessárias. 

#### Função de busca KMP

~~~C
int buscaKMP(char *texto, char *padrao){
    int i;
    int *preProcess = preProcessamentoKMP(padrao);
    int j = -1;

    if(!preProcess){
        return -1;
    }

    for(i = 0 ; i < N ; i++){
        while (j > -1 && padrao[j+1] != texto[i]){
            j = preProcess[j];
        }

        if(texto[i] == padrao[j+1]){
            j++;
        }

        if(j == M-1){
            return i-j;
        }
        
    }

    return -1;
}
~~~


### Fontes
[Teoria sobre busca KMP](https://www.youtube.com/watch?v=V5-7GzOfADQ)
[Implementação do algoritmo de busca KMP](https://youtu.be/d2oTD98Aj6Q)
