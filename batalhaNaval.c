#include <stdio.h>

int main() {
int tabuleiro[10][10] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            };

    // Navio verticalmente na coluna 0
    for (int i = 0; i < 3; i++) { 
        tabuleiro[i][0] = 1;
    }

    // Navio horizontal na linha 4
    for (int j = 3; j < 6; j++) {
        tabuleiro[4][j] = 1;
    }

    // Coordenadas dos navios
    printf("Coordenadas dos navios:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (tabuleiro[i][j] == 1) {
                printf("Navio na posição (%d, %d)\n", i, j);
            }
        }
    }

    // Print do tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}