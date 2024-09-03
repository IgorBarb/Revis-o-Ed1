/*
O código apresenta uma lista duplamente ligada com operações básicas para inserir, deletar e imprimir.

1 - comente o código.
2 - Modifique a operação de inserção de dados, para que o usuário seja capaz de inserir valores para a lista.
3 - Faça uma operação de buscar por um valor específico, informado pelo usuário, onde o programa deve apresentar se o valor foi encontrado e, em caso afirmativo, exibir detalhes(vizinhos) do nó correspondente.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void deleteNode(Node* node) {
    if (node == head)
        head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    free(node);
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertFront(10);
    insertFront(20);
    printList();
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // Definimos a estrutura do nó para a lista duplamente ligada
    int data;                // Valor armazenado no nó
    struct Node* next;       // Ponteiro para o próximo nó
    struct Node* prev;       // Ponteiro para o nó anterior
} Node;

Node* head = NULL; // Cabeça da lista, inicialmente nula

void insertFront(int value) { // Função para inserir um nó no início da lista
    Node* newNode = (Node*)malloc(sizeof(Node)); // Aloca memória para o novo nó
    newNode->data = value;                      // Define o valor do nó
    newNode->next = head;                       // O próximo do novo nó é o antigo head
    newNode->prev = NULL;                       // O anterior do novo nó é nulo
    if (head != NULL)                           // Se a lista não estiver vazia
        head->prev = newNode;                   // Define o anterior do antigo head como o novo nó
    head = newNode;                            // Atualiza o head para o novo nó
}

void deleteNode(Node* node) { // Função para deletar um nó específico da lista
    if (node == head)                         // Se o nó a ser deletado é o head
        head = node->next;                   // Atualiza o head para o próximo nó
    if (node->next != NULL)                   // Se o nó a ser deletado não é o último
        node->next->prev = node->prev;       // Atualiza o ponteiro prev do próximo nó
    if (node->prev != NULL)                   // Se o nó a ser deletado não é o primeiro
        node->prev->next = node->next;       // Atualiza o ponteiro next do nó anterior
    free(node);                               // Libera a memória do nó
}

void printList() { // Função para imprimir a lista
    Node* temp = head;                       // Começa pelo head
    while (temp != NULL) {                  // Enquanto houver nós
        printf("%d ", temp->data);          // Imprime o valor do nó
        temp = temp->next;                 // Move para o próximo nó
    }
    printf("\n");                           // Imprime uma nova linha ao final
}

void searchValue(int value) { // Função para buscar um valor na lista
    Node* temp = head;                       // Começa pelo head
    while (temp != NULL) {                  // Enquanto houver nós
        if (temp->data == value) {          // Se o valor do nó corresponder ao valor procurado
            printf("Valor %d encontrado.\n", value);
            printf("Detalhes do nó encontrado:\n");
            printf("Valor: %d\n", temp->data);
            printf("Anterior: %s\n", temp->prev ? "Sim" : "Não");
            printf("Próximo: %s\n", temp->next ? "Sim" : "Não");
            return;
        }
        temp = temp->next;                 // Move para o próximo nó
    }
    printf("Valor %d não encontrado.\n", value); // Se o valor não foi encontrado
}

int main() {
    int choice, value;

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Inserir valor\n");
        printf("2. Imprimir lista\n");
        printf("3. Buscar valor\n");
        printf("4. Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printList();
                break;
            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &value);
                searchValue(value);
                break;
            case 4:
                return 0;
            default:
                printf("Escolha inválida. Tente novamente.\n");
        }
    }

    return 0;
}
