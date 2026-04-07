#include <stdio.h>
#include <stdlib.h> 


#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para exibir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para criar matriz de habilidade Cone (ponta para baixo)
void criarCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Definindo a forma de cone
            if (j >= (TAM_HABILIDADE/2 - i) && j <= (TAM_HABILIDADE/2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade Cruz
void criarCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == meio || j == meio) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função para criar matriz de habilidade Octaedro (losango)
void criarOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= meio - abs(meio - i) && j <= meio + abs(meio - i)) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Função para sobrepor habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha - meio + i;
            int colTab = origemColuna - meio + j;

            // Checar se está dentro do tabuleiro e se é água ou navio
            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colTab >= 0 && colTab < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linhaTab][colTab] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Colocar alguns navios de exemplo
    tabuleiro[2][3] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[7][7] = 3;

    // Criar matrizes de habilidade
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Definir pontos de origem no tabuleiro
    int origemConeLinha = 1, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaedroLinha = 7, origemOctaedroColuna = 7;

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna);

    // Exibir tabuleiro final
    printf("Tabuleiro com habilidades:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}