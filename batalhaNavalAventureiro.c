#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    int tabuleiro[TAM][TAM] = {0};
    int i, j;

    int l1 = 0, c1 = 0; 
    if (l1 + TAM_NAVIO <= TAM) 
        for (i = 0; i < TAM_NAVIO; i++) tabuleiro[l1 + i][c1] = NAVIO;

    int l2 = 4, c2 = 3; 
    if (c2 + TAM_NAVIO <= TAM) 
        for (j = 0; j < TAM_NAVIO; j++) tabuleiro[l2][c2 + j] = NAVIO;

    int l3 = 2, c3 = 2; 
    if (l3 + TAM_NAVIO <= TAM && c3 + TAM_NAVIO <= TAM) 
        for (i = 0; i < TAM_NAVIO; i++) tabuleiro[l3 + i][c3 + i] = NAVIO;

    int l4 = 1, c4 = 8; 
    if (l4 + TAM_NAVIO <= TAM && c4 - (TAM_NAVIO - 1) >= 0) 
        for (i = 0; i < TAM_NAVIO; i++) tabuleiro[l4 + i][c4 - i] = NAVIO;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}