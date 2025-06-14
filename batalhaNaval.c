#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3

// Função para verificar se é possível posicionar o navio (sem sair e sem sobreposição)
int pode_posicionar(int tabuleiro[10][10], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        // Calcula as próximas posições com base na direção
        if (direcao == 'H') c += i;              // Horizontal →
        else if (direcao == 'V') l += i;         // Vertical ↓
        else if (direcao == 'D') { l += i; c += i; } // Diagonal ↘
        else if (direcao == 'E') { l += i; c -= i; } // Diagonal ↙

        // Verifica se está dentro dos limites
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return 0;

        // Verifica sobreposição
        if (tabuleiro[l][c] != 0)
            return 0;
    }

    return 1;
}

// Função para posicionar o navio
void posicionar_navio(int tabuleiro[10][10], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (direcao == 'H') c += i;
        else if (direcao == 'V') l += i;
        else if (direcao == 'D') { l += i; c += i; }
        else if (direcao == 'E') { l += i; c -= i; }

        tabuleiro[l][c] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void exibir_tabuleiro(int tabuleiro[10][10]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas e direções dos 4 navios
    int navios[4][2] = {
        {1, 2},  // Navio horizontal
        {4, 5},  // Navio vertical
        {0, 0},  // Navio diagonal ↘
        {0, 9}   // Navio diagonal ↙
    };
    char direcoes[4] = {'H', 'V', 'D', 'E'};  // Direções correspondentes

    // Tenta posicionar os navios
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        char direcao = direcoes[i];

        if (pode_posicionar(tabuleiro, linha, coluna, direcao)) {
            posicionar_navio(tabuleiro, linha, coluna, direcao);
        } else {
            printf("Erro ao posicionar navio %d na posicao (%d, %d) direcao %c\n", i + 1, linha, coluna, direcao);
            return 1;
        }
    }

    // Exibe o tabuleiro final
    exibir_tabuleiro(tabuleiro);

    return 0;
}

