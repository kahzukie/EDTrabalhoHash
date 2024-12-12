#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
  int key;
  int value;
  int deleted; // Campo para avisar se o nó foi removido
  struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

// Função hash simples (Método da Divisão)
/* int hashFunction(int key) { return key % TABLE_SIZE; } */

// Função hash (Método da Multiplicação)
/* Usamos fmod para pegar o resto como recomendado no exercicio, e multiplicamos
 * pelo TABLE_SIZE para pegar o valor da hash */
int hashFunction(int key) { return TABLE_SIZE * fmod(key, 0.618033); }

// Inserção na tabela hash
void insert(int key, int value) {
  int hashIndex = hashFunction(key);
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = hashTable[hashIndex];
  hashTable[hashIndex] = newNode;
}

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
}

// Exibição da tabela hash
void displayTable() {
  int i;
  for (i = 0; i < TABLE_SIZE; i++) {
    printf("[%d]: ", i);
    Node *current = hashTable[i];
    while (current) {
      printf("(Key: %d, Value: %d) -> ", current->key, current->value);
      current = current->next;
    }
    printf("NULL\n");
  }
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

  removeElement(11);
  printf("Tabela apos remocao:\n");
  displayTable();
  return 0;
}
