#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO_TABULEIRO 10
// Valor que representa parte de um navio
#define NAVIO 3
// Tamanho fixo dos navios
#define TAMANHO_NAVIO 3

int main() {
    // Declaração da matriz do tabuleiro e inicialização com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (definidas diretamente)
    int linha_horizontal = 2, coluna_horizontal = 4; // navio horizontal
    int linha_vertical = 5, coluna_vertical = 1;     // navio vertical

    // Verificação se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica sobreposição antes de posicionar
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            // Posiciona o navio horizontal
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
            }
        } else {
            printf("Erro: sobreposição no posicionamento do navio horizontal.\n");
            return 1;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificação se o navio vertical cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            // Posiciona o navio vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
            }
        } else {
            printf("Erro: sobreposição no posicionamento do navio vertical.\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibição do tabuleiro no console
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
