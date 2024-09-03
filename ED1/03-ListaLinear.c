/*
O código abaixo apresenta a implementação de uma lista linear.

Para esse exemplo, faça:
- Implemente funções adicionais como buscar(int elemento) para encontrar a posição de um elemento na lista.
ou 
- Adicione métodos para inverter a lista, encontrar o máximo/mínimo, ou ordenar a lista.

#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    imprimir();
    remover(1);
    imprimir();
    return 0;
}
*/
#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

// Função para inserir um elemento na lista
void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

// Função para remover um elemento da lista pelo índice
void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

// Função para imprimir os elementos da lista
void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

// Função para buscar um elemento e retornar sua posição
int buscar(int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            return i;
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    inserir(5);
    inserir(15);

    printf("Lista original:\n");
    imprimir();

    // Buscar
    int elemento = 20;
    int pos = buscar(elemento);
    if (pos != -1) {
        printf("Elemento %d encontrado na posição %d.\n", elemento, pos);
    } else {
        printf("Elemento %d não encontrado.\n", elemento);
    }

    return 0;
}

