/*
O código abaixo apresenta a implementação de uma fila e suas operações básicas.

1 - comente o código
2 - implemente uma função para contar o número de elementos na fila.
3 - implemente uma função para limpar todos os elementos da fila, liberando memória apropriadamente.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) { 
        q->front = q->rear = newNode;
    } else { 
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) { 
        printf("Fila está vazia.\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;
    printf("Elementos da fila: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);

    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // Definimos a estrutura do nó da fila
    int data;             // Dados armazenados no nó
    struct Node* next;    // Ponteiro para o próximo nó
} Node;

typedef struct Queue { // Definimos a estrutura da fila
    Node* front; // Ponteiro para o início da fila
    Node* rear;  // Ponteiro para o final da fila
} Queue;

Queue* createQueue() { // Função para criar uma fila
    Queue* q = (Queue*)malloc(sizeof(Queue)); // Aloca memória para a fila
    if (q == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL; // Inicializa a fila como vazia
    return q;
}

void enqueue(Queue* q, int value) { // Função para adicionar um elemento à fila
    Node* newNode = (Node*)malloc(sizeof(Node)); // Aloca memória para o novo nó
    if (newNode == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value; // Define o valor do nó
    newNode->next = NULL; // O próximo nó é nulo
    if (q->rear == NULL) { // Se a fila estiver vazia
        q->front = q->rear = newNode; // O novo nó é o início e o final da fila
    } else { // Se a fila não estiver vazia
        q->rear->next = newNode; // Adiciona o novo nó ao final da fila
        q->rear = newNode; // Atualiza o final da fila
    }
}

int dequeue(Queue* q) { // Função para remover um elemento da fila
    if (q->front == NULL) { // Verifica se a fila está vazia
        printf("Fila está vazia.\n");
        return -1; // Retorna -1 para indicar erro
    }
    Node* temp = q->front; // Armazena o nó a ser removido
    int data = temp->data; // Obtém o dado do nó
    q->front = q->front->next; // Atualiza o início da fila
    if (q->front == NULL) { // Se a fila ficar vazia após a remoção
        q->rear = NULL; // Atualiza o final da fila
    }
    free(temp); // Libera a memória do nó removido
    return data; // Retorna o dado removido
}

int isEmpty(Queue* q) { // Função para verificar se a fila está vazia
    return q->front == NULL; // Retorna 1 se a fila estiver vazia, 0 caso contrário
}

int countElements(Queue* q) { // Função para contar o número de elementos na fila
    int count = 0;
    Node* temp = q->front; // Começa pelo início da fila
    while (temp != NULL) { // Percorre a fila até o final
        count++; // Incrementa o contador
        temp = temp->next; // Move para o próximo nó
    }
    return count; // Retorna o número de elementos
}

void clearQueue(Queue* q) { // Função para limpar todos os elementos da fila e liberar a memória
    Node* temp;
    while (q->front != NULL) { // Enquanto a fila não estiver vazia
        temp = q->front; // Armazena o nó a ser removido
        q->front = q->front->next; // Atualiza o início da fila
        free(temp); // Libera a memória do nó removido
    }
    q->rear = NULL; // Atualiza o final da fila
}

void printQueue(Queue* q) { // Função para imprimir os elementos da fila
    if (isEmpty(q)) { // Verifica se a fila está vazia
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front; // Começa pelo início da fila
    printf("Elementos da fila: ");
    while (temp != NULL) { // Percorre a fila até o final
        printf("%d ", temp->data); // Imprime o dado do nó atual
        temp = temp->next; // Move para o próximo nó
    }
    printf("\n"); // Imprime uma nova linha ao final
}

int main() {
    Queue* q = createQueue(); // Cria uma nova fila
    enqueue(q, 10); // Adiciona 10 à fila
    enqueue(q, 20); // Adiciona 20 à fila
    enqueue(q, 30); // Adiciona 30 à fila
    printQueue(q); // Imprime o conteúdo da fila

    printf("Número de elementos na fila: %d\n", countElements(q)); // Conta e imprime o número de elementos

    printf("Desenfileirado: %d\n", dequeue(q)); // Remove e imprime o elemento do início da fila
    printQueue(q); // Imprime o conteúdo da fila
    printf("Número de elementos na fila: %d\n", countElements(q)); // Conta e imprime o número de elementos

    printf("Desenfileirado: %d\n", dequeue(q)); // Remove e imprime o elemento do início da fila
    printQueue(q); // Imprime o conteúdo da fila
    printf("Número de elementos na fila: %d\n", countElements(q)); // Conta e imprime o número de elementos

    printf("Desenfileirado: %d\n", dequeue(q)); // Remove e imprime o elemento do início da fila
    printQueue(q); // Imprime o conteúdo da fila
    printf("Número de elementos na fila: %d\n", countElements(q)); // Conta e imprime o número de elementos

    clearQueue(q); // Limpa a fila e libera a memória
    free(q); // Libera a memória da estrutura da fila

    return 0; // Finaliza o programa
}
