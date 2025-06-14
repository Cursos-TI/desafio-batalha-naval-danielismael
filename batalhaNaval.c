#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

#define NAVIO 3
#define AGUA 0
#define AREA_AFETADA 5

// Função para inicializar uma matriz 5x5 com a forma do cone (ponta para cima)
void criar_matriz_cone(int matriz[5][5]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Forma de cone: parte de 1 célula e cresce até 5
            if (j >= 2 - i && j <= 2 + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para inicializar uma matriz 5x5 com a forma da cruz
void criar_matriz_cruz(int matriz[5][5]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Linha e coluna centrais
            if (i == 2 || j == 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para inicializar uma matriz 5x5 com a forma do octaedro (losango)
void criar_matriz_octaedro(int matriz[5][5]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Losango: distância de (2,2) não pode passar de 2
            if (abs(i - 2) + abs(j - 2) <= 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Sobrepõe a matriz de habilidade no tabuleiro na posição (linha, coluna)
void aplicar_habilidade(int tabuleiro[10][10], int habilidade[5][5], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origem_linha - 2 + i;
                int coluna = origem_coluna - 2 + j;

                // Verifica se está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAMANHO_TABULEIRO &&
                    coluna >= 0 && coluna < TAMANHO_TABULEIRO) {

                    // Marca com 5 apenas se não for parte de navio
                    if (tabuleiro[linha][coluna] == AGUA) {
                        tabuleiro[linha][coluna] = AREA_AFETADA;
                    }
                }
            }
        }
    }
}

// Exibe o tabuleiro com representações visuais
void exibir_tabuleiro(int tabuleiro[10][10]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) printf(". ");
            else if (tabuleiro[i][j] == NAVIO) printf("N ");
            else if (tabuleiro[i][j] == AREA_AFETADA) printf("* ");
        }
        printf("\n");
    }
}

int main() {
    // Tabuleiro inicial
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona alguns navios manualmente (horizontal e diagonal)
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;

    tabuleiro[5][5] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][7] = NAVIO;

    // Matrizes das habilidades
    int cone[5][5], cruz[5][5], octaedro[5][5];

    // Cria as formas das habilidades
    criar_matriz_cone(cone);
    criar_matriz_cruz(cruz);
    criar_matriz_octaedro(octaedro);

    // Aplica habilidades em diferentes posições
    aplicar_habilidade(tabuleiro, cone, 1, 4);       // Cone centrado em (1,4)
    aplicar_habilidade(tabuleiro, cruz, 5, 2);       // Cruz centrada em (5,2)
    aplicar_habilidade(tabuleiro, octaedro, 7, 7);   // Octaedro centrado em (7,7)

    // Mostra resultado
    exibir_tabuleiro(tabuleiro);

    return 0;
}
