#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    // Inicializando
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posição dos navios
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][0] = 3;
    }
    for (int j = 3; j < 6; j++) {
        tabuleiro[4][j] = 3;
    }

    // Print dos navios
    printf("Coordenadas dos navios (valor 3):\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 3) {
                printf("Navio na posição (%d, %d)\n", i, j);
            }
        }
    }

    // Print do tabuleiro completo
    printf("\nTabuleiro (0 = água, 3 = navio):\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}