/*
O código abaixo apresenta a implementação de uma pilha e suas operações básicas.

1 - comente o código
2 - implemente uma função para verificar se a pilha está vazia.
3 - proponha uma função que possa fazer expansão dinâmica quando a capacidade máxima é atingida, em vez de simplesmente negar novas inserções na pilha.

#include <stdio.h>
#define MAX_SIZE 3

int pilha[MAX_SIZE];
int topo = -1;

void push(int elemento) {
    if (topo < MAX_SIZE - 1) {
        pilha[++topo] = elemento;
    } else {
        printf("Pilha cheia!\n");
    }
}

int pop() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo--];
    }
}

int top() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo];
    }
}

void imprimir() {
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    imprimir();
    printf("Elemento no topo: %d\n", top());
    printf("Elemento removido: %d\n", pop());
    imprimir();
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h> // Para alocar e liberar memória

#define INITIAL_SIZE 3 // Inicializamos a capacidade máxima da pilha

typedef struct {
    int *array;    // Ponteiro para o array que representa a pilha
    int topo;      // Índice do topo da pilha
    int capacity;  // Capacidade atual da pilha
} Pilha;

void initializePilha(Pilha *p, int initialSize) { // Função para inicializar a pilha
    p->array = (int*)malloc(initialSize * sizeof(int));
    p->topo = -1;
    p->capacity = initialSize;
}

int isEmpty(Pilha *p) { // Função para verificar se a pilha está vazia
    return p->topo == -1;
}

void expandPilha(Pilha *p) { // Função para expandir a pilha dinamicamente
    int newCapacity = p->capacity * 2;
    int *newArray = (int*)malloc(newCapacity * sizeof(int));
    
    for (int i = 0; i <= p->topo; i++) { // Copia os elementos da pilha antiga para a nova pilha
        newArray[i] = p->array[i];
    }
    
    free(p->array); // Libera a memória do array antigo e atualiza a pilha
    p->array = newArray;
    p->capacity = newCapacity;
}

void push(Pilha *p, int elemento) { // Função para adicionar um elemento à pilha
    if (p->topo >= p->capacity - 1) {
        expandPilha(p); // Expande a pilha se necessário
    }
    p->array[++p->topo] = elemento; // Adiciona o elemento e atualiza o topo
}

int pop(Pilha *p) { // Função para remover e retornar o elemento do topo da pilha
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return p->array[p->topo--]; // Retorna o elemento do topo e atualiza o topo
    }
}

int top(Pilha *p) { // Função para obter o elemento no topo da pilha sem removê-lo
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return p->array[p->topo]; // Retorna o elemento do topo
    }
}

void imprimir(Pilha *p) { // Função para imprimir o conteúdo da pilha
    printf("Conteúdo da pilha:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->array[i]); // Imprime o elemento atual
    }
    printf("\n"); // Imprime uma nova linha ao final
}

int main() {
    Pilha p;
    initializePilha(&p, INITIAL_SIZE); // Inicializa a pilha com tamanho inicial

    push(&p, 10); // Adiciona 10 à pilha
    push(&p, 20); // Adiciona 20 à pilha
    push(&p, 30); // Adiciona 30 à pilha
    imprimir(&p); // Imprime o conteúdo da pilha
    
    printf("Elemento no topo: %d\n", top(&p)); // Imprime o elemento no topo da pilha
    
    printf("Elemento removido: %d\n", pop(&p)); // Remove e imprime o elemento do topo
    imprimir(&p); // Imprime o conteúdo da pilha novamente

    free(p.array); // Libera a memória alocada para a pilha

    return 0;
}
