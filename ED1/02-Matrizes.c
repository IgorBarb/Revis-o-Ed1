/*
O código abaixo recebe do usuário elementos que são inseridos em uma matriz 3x3, em seguida, imprime a soma de sua diagonal principal.
- faça uma modificação para que seja possível dinamizar o tamanho da matriz (utilizar alocação dinâmica de memória usando malloc)


#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j, soma = 0;

    printf("Insira os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h> // Para malloc e free

int main() {
    int n, i, j;
    int **matriz; // Ponteiro para a matriz
    int soma = 0;

    printf("Digite o tamanho da matriz (n x n): "); // Solicita o tamanho da matriz ao usuário
    scanf("%d", &n);

    matriz = (int **)malloc(n * sizeof(int *)); // Aloca memória dinamicamente para a matriz
    if (matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            for (int k = 0; k < i; k++) {  // Libera a memória já alocada em caso de erro
                free(matriz[k]);
            }
            free(matriz);
            return 1;
        }
    }

    printf("Insira os elementos da matriz %dx%d:\n", n, n); // Preenche a matriz com valores fornecidos pelo usuário
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < n; i++) { // Calcula a soma dos elementos da diagonal principal
        soma += matriz[i][i];
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma); // Imprime a soma dos elementos da diagonal principal
    
    for (i = 0; i < n; i++) { // Libera a memória alocada
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
