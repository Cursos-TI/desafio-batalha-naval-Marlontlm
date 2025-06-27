#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para imprimir o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Cabeçalho das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d: ", i); // Cabeçalho das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o posicionamento é válido
bool podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') { // Horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
            return false;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != AGUA)
                return false;
        }
    } else if (orientacao == 'V') { // Vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
            return false;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != AGUA)
                return false;
        }
    }
    return true;
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (podePosicionar(tabuleiro, linha, coluna, orientacao)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (orientacao == 'H') {
                tabuleiro[linha][coluna + i] = NAVIO;
            } else if (orientacao == 'V') {
                tabuleiro[linha + i][coluna] = NAVIO;
            }
        }
    } else {
        printf("Erro: Não foi possível posicionar o navio na linha %d e coluna %d na orientação %c.\n", linha, coluna, orientacao);
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas definidas diretamente no código:
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;

    // Posicionar navios
    posicionarNavio(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, 'H');
    posicionarNavio(tabuleiro, linhaNavioVertical, colunaNavioVertical, 'V');

    // Exibir tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
