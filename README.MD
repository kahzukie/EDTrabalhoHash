# Parte 1: Exploração Teórica e Comparativa
## 1. Explique a importância do espalhamento uniforme em funções hash.
- A importância do espalhamento uniforme seria para não pesar computacionalmente a tabela hash

## 2. Descreva uma situação em que o fator de carga alto pode comprometer o desempenho.
- Ocorreria um aumento de colisão, onde poderia aumentar o tempo de execução nas operações.  
- Poderia gerar uma lista linear fazendo com que as vantagens de uma tabela hash seja anulada.  
- O tempo de busca seria aumentado pois teria que passar por mais posições até encontrar o elemento desejado ou um local livre.

# Parte 2: Código Base e Análise
## 3. Analise e responda se o código base apresenta problemas de colisão.
- Sim, ocorre colisões pois os restos dos inserts de chave 1, 11, 21 serão 0, o que tos leva a mesma chave na tabela hash

## 4. Explique como o encadeamento é usado para resolver colisões no programa
- O encadeamento é usado pois caso não fosse haveria colisões nas chaves 1 pois o elemento é inserido no indice em que mais de um elemento está sendo inserido.

## 5. Qual seria o impacto de usar um tamanho de tabela pequeno (menor do que 5, por exemplo), considerando a mesma quantidade de itens que são inseridos pelo programa na tabela?
- O impacto seria que com um tamanho pequeno, ocorreria muitas colisões, fazendo assim com que perca eficiencia, e uma grande degradação no desempenho.

## 6. O código apresentado utiliza o Método da Divisão na função hash, no qual temos: index = chave % TamanhoTabela. Explique a lógica de funcionamento do Método da Divisão
- O funcionamento do metodo é que para calcular o indice ele divide a chave do elemento pelo tamanho da tabela e o resto da divisão vira o indice da hash.

# Parte 3: Modificações e Melhorias
## 7. Apresente o código para a função de remoção (com comentários explicativos no código)
- Foram feitas alterações no código tanto como a adição da função para a remoção, sendo elas:
```c
typedef struct Node {
  int key;
  int value;
  int deleted; // Campo para avisar se o nó foi removido
  struct Node *next;
} Node;

// Busca na tabela hash
int search(int key) {
  int hashIndex = hashFunction(key);
  Node *current = hashTable[hashIndex];
  while (current) {
    if (!current->deleted &&
        current->key ==
            key) { // Verifica se o nó não está marcado como deletado
      return current->value;
    }
    current = current->next;
  }
  return -1; // Não encontrado

// Função para remover o elemento
void removeElement(int key) {
  /* Pega as informações ta hash */
  int hashIndex = hashFunction(key);
  Node *current = hashTable[hashIndex];
  Node *previous = NULL;

  /* Loop para pegar o current state e deleta-lo, fazendo assim o previous key
   * virar o next */
  while (current) {
    if (current->key == key) {

      if (previous == NULL) {
        /* Tratamento para quando previous for NULL, ele pega o index da hash e
         * passa para a proxima */
        hashTable[hashIndex] = current->next;
      } else {
        /* Caso nao seja null ele pega o valor da hash e seta como current */
        previous->next = current->next;
      }
      /* libera a memoria de current (ou seja deleta ele da lista) */
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
  /* Printa elemento não encontrado caso não o ache */
  printf("Elemento não encontrado.\n");
}

int main() {
  int i;

  // Inicializando todos os elementos da tabela hash com NULL
  for (i = 0; i < TABLE_SIZE; i++) {
    hashTable[i] = NULL;
  }
  // insert(key, value)
  insert(1, 10);
  insert(11, 20);
  insert(21, 30);
  insert(2, 15);

  printf("Tabela Hash:\n");
  displayTable();

  int key = 11;
  int value = search(key);
  if (value != -1) {
    printf("Valor encontrado para a chave %d: %d\n", key, value);
  } else {
    printf("Chave %d nao encontrada.\n", key);
  }

  // Inserindo a função para remover o elemento de chave 11
  removeElement(11);
  // Print para diferenciar a tabela de inserção com a de remoção
  printf("Tabela apos remocao:\n");
  // Mostrando a tabela nova
  displayTable();
  return 0;
}
```
## 8. Discuta a importância e as dificuldades envolvidas para realizar o Redimensionamento Dinâmico de Tabela Hash.
- É importante pois quando a tabela fica muito cheia, colisões se tornam algo mais frequentes, fazendo o desempenho ficar pior nas operação de inserção, busca e remoção.  
- A dificuldade é pois temos que implementar um monitoramento para o fator de carga, onde caso o ultrapasse irá criar uma nova tabela que irá alocar o tamanho novo desejado, para então reinserir os dados da tabela antiga na nova e só então liberar a memória da tabela antiga.

# Parte 4: Experimente Diferentes Funções Hash
## 9. Apresente o código para a função hashFunction implementando o Método da Multiplicação (com comentários explicativos no código).
- Foi implementada nova função hashFunction e comentada a função hashFunction anterior:
```c
// Função hash simples (Método da Divisão)
/* int hashFunction(int key) { return key % TABLE_SIZE; } */

// Função hash (Método da Multiplicação)
/* Usamos fmod para pegar o resto como recomendado no exercicio, e multiplicamos
 * pelo TABLE_SIZE para pegar o valor da hash */
int hashFunction(int key) { return TABLE_SIZE * fmod(key, 0.618033); }
```

## 10. Compare a distribuição de chaves proporcionada pelo Método da Multiplicação com a Distribuição obtida pelo método da Divisão.
- Foi visualizado menos uma tabela com menos colisões, o que melhora o desempenho da tabela hash.

## 11. Pesquise e explique com suas palavras como poderia ser implementada uma função Hash para chaves do tipo string.
- Há várias formas, podendo usar a soma dos codigos ascii de cada caractere da string, como também multiplicar cada caractere pelo seu indice e por um número primo, somando os resultados.  
- Sobre a soma pelos códigos ascii temos a vantagem de ser simples de implementar, mas com a desvantagem que a distribuição pode não ser regular, principalmente para strings com padrões simples.  
- Já por multiplicação dos números primos, há uma melhora na distribuição comparado com a ascii, mas pode pesar mais computacionalmente.  
- Há também a forma mais usada atualmente, que utilizam os algoritimos MD5 ou SHA-256 para gerar uma hash de tamanho fixo, onde sua vantagem é a alta resistencia a colisões, mas tem de desvantagem um alto custo computacional que é desnecessário para tabelas hash simples.

# Parte 5: Conclusões
## 12. Quais os principais aprendizados que foram alcançados com a realização deste trabalho sobre Tabelas Hash? Quais as dificuldades? Quais as limitações? Quais as possibilidades de aplicação de Tabelas? Elabore uma conclusão sobre o trabalho realizado, considerando esses e outros aspectos. 
### Igor:
- Os principais aprendizados que tive deste trabalho, foram que uma hash é muito mais complexa do que "Números aleatório" com suas colisões e fator de carga, tanto como diferentes métodos para a criação da hash, e a importância de escolher diferentes hash, pois afetam diretamente o desempenho da tabela.  
- Foi bem trabalhoso entender como implementar um redimensionamento dinâmico, mesmo sendo muito importante, pois uma tabela pode ultrapassar o seu tamanho tendo assim que aumenta-la para suprir sua nescessidade.  
- Tabelas hash podem consumir quantidades significativas de memória, principalmente quando há um número elevado de elementos.  
- É possível fazer o gerenciamento de objetos e entidades em um jogo com tabela hash.  
- Então para concluir, vemos que tabelas hash são estruturas de dados com uma ampla gama de aplicações, e que com este trabalho trabalhamos com os principais conceitos relacionados a elas, como também as dificuldades encontradas ao implementar e suas possiveis soluções para otimizar desempenho.
