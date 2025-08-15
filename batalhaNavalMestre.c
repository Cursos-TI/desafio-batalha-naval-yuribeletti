#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

void inicializar_tabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf(" 0 ");
            else if (tabuleiro[i][j] == NAVIO)
                printf(" 3 ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf(" 5 ");
        }
        printf("\n");
    }
}

void posicionar_navio(int tabuleiro[TAM][TAM], int l, int c, int orientacao) {
    if (orientacao == 0) { // Vertical
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[l + i][c] = NAVIO;
        }
    } else { // Horizontal
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[l][c + i] = NAVIO;
        }
    }
}

void aplicar_habilidade_cone(int tabuleiro[TAM][TAM], int l, int c) {
    int cone[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1 && l + i < TAM && c + j < TAM) {
                tabuleiro[l + i][c + j] = HABILIDADE;
            }
        }
    }
}

void aplicar_habilidade_cruz(int tabuleiro[TAM][TAM], int l, int c) {
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1 && l + i < TAM && c + j < TAM) {
                tabuleiro[l + i][c + j] = HABILIDADE;
            }
        }
    }
}

void aplicar_habilidade_octaedro(int tabuleiro[TAM][TAM], int l, int c) {
    int octaedro[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1 && l + i < TAM && c + j < TAM) {
                tabuleiro[l + i][c + j] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializar_tabuleiro(tabuleiro);

    int l1 = 0, c1 = 0;
    posicionar_navio(tabuleiro, l1, c1, 0);

    int l2 = 4, c2 = 3;
    posicionar_navio(tabuleiro, l2, c2, 1);

    int l3 = 2, c3 = 2;
    posicionar_navio(tabuleiro, l3, c3, 0);

    int l4 = 1, c4 = 8;
    posicionar_navio(tabuleiro, l4, c4, 1);

    printf("Tabuleiro com navios:\n");
    exibir_tabuleiro(tabuleiro);

    printf("\nAplicando habilidade Cone:\n");
    int tabuleiro_cone[TAM][TAM];
    inicializar_tabuleiro(tabuleiro_cone);
    aplicar_habilidade_cone(tabuleiro_cone, 2, 2);
    exibir_tabuleiro(tabuleiro_cone);

    printf("\nAplicando habilidade Cruz:\n");
    int tabuleiro_cruz[TAM][TAM];
    inicializar_tabuleiro(tabuleiro_cruz);
    aplicar_habilidade_cruz(tabuleiro_cruz, 2, 2);
    exibir_tabuleiro(tabuleiro_cruz);

    printf("\nAplicando habilidade Octaedro:\n");
    int tabuleiro_octaedro[TAM][TAM];
    inicializar_tabuleiro(tabuleiro_octaedro);
    aplicar_habilidade_octaedro(tabuleiro_octaedro, 2, 2);
    exibir_tabuleiro(tabuleiro_octaedro);

    return 0;
}