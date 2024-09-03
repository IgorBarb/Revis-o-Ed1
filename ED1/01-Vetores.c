/*
O código abaixo realiza a impressão do vetor na ordem inversa.
1 - comente o código
2 - faça uma modificação para que seja possível inserir um vetor de n elementos.

#include <stdio.h>

int main() {
    int vetor[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, temp;

    for (i = 0; i < 5; i++) {
        temp = vetor[i];
        vetor[i] = vetor[9 - i];
        vetor[9 - i] = temp;
    }

    printf("Vetor invertido:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h> // Para malloc e free

int main() {
    int n, i;
    int *vetor; // Ponteiro para o vetor

    printf("Digite o número de elementos do vetor: "); // Solicita o tamanho do vetor ao usuário
    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int)); // Aloca memória dinamicamente para o vetor
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos do vetor:\n"); // Preenche o vetor com valores fornecidos pelo usuário
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < n / 2; i++) {   // Inverte o vetor
        int temp = vetor[i];
        vetor[i] = vetor[n - 1 - i];
        vetor[n - 1 - i] = temp;
    }

    printf("Vetor invertido:\n"); // Imprime o vetor invertido
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor); // Libera a memória alocada

    return 0;
}
