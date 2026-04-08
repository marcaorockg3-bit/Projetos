#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// --- Constantes Globais ---
#define NUM_TERRITORIOS 6
#define MAX_NOME 50
#define MISSAO_CONQUISTA 1
#define MISSAO_ELIMINACAO 2

// --- Estrutura de Dados ---
typedef struct {
    char nome[MAX_NOME];
    char dono[MAX_NOME];
    int tropas;
} Territorio;

// --- Protótipos ---
Territorio* alocarMapa();
void inicializarTerritorios(Territorio* mapa);
void liberarMemoria(Territorio* mapa);
void exibirMapa(const Territorio* mapa);
void exibirMissao(int idMissao);
void simularAtaque(Territorio* mapa, int origem, int destino);
int verificarVitoria(const Territorio* mapa, int idMissao, const char* corJogador);
void limparBufferEntrada();

// --- Função Principal ---
int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Territorio* mapa = alocarMapa();
    if (!mapa) return 1;

    inicializarTerritorios(mapa);

    int missaoAtual = (rand() % 2) + 1;
    char corJogador[] = "Azul";
    int opcao;

    do {
        system("cls || clear");

        printf("=== WAR ESTRUTURADO ===\n");

        exibirMissao(missaoAtual);
        exibirMapa(mapa);

        printf("\n1. Atacar\n");
        printf("2. Verificar Missao\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1: {
                int o, d;

                printf("ID Origem (0-5) e Destino (0-5): ");
                scanf("%d %d", &o, &d);

                simularAtaque(mapa, o, d);
                break;
            }

            case 2:
                if (verificarVitoria(mapa, missaoAtual, corJogador)) {
                    printf("\nPARABENS! Voce cumpriu sua missao!\n");
                    opcao = 0;
                } 
                else {
                    printf("\nMissao ainda nao cumprida. Continue lutando!\n");
                }
                break;
        }

        if(opcao != 0) {
            printf("\nPressione Enter...");
            limparBufferEntrada();
            getchar();
        }

    } while (opcao != 0);

    liberarMemoria(mapa);

    return 0;
}

// --- Implementação das Funções ---

Territorio* alocarMapa() {
    return (Territorio*)calloc(NUM_TERRITORIOS, sizeof(Territorio));
}

void inicializarTerritorios(Territorio* mapa) {

    char* nomes[] = {"Brasil", "Argentina", "Egito", "Russia", "Japao", "Australia"};
    char* cores[] = {"Azul", "Vermelho", "Amarelo", "Azul", "Vermelho", "Amarelo"};

    for (int i = 0; i < NUM_TERRITORIOS; i++) {

        strcpy(mapa[i].nome, nomes[i]);
        strcpy(mapa[i].dono, cores[i]);

        mapa[i].tropas = (rand() % 5) + 2;
    }
}

void exibirMapa(const Territorio* mapa) {

    printf("\nID | TERRITORIO   | DONO       | TROPAS\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < NUM_TERRITORIOS; i++) {

        printf("%-2d | %-12s | %-10s | %d\n",
               i,
               mapa[i].nome,
               mapa[i].dono,
               mapa[i].tropas);
    }
}

void exibirMissao(int idMissao) {

    printf("SUA MISSAO: ");

    if (idMissao == MISSAO_CONQUISTA)
        printf("Conquistar pelo menos 4 territorios.\n");
    else
        printf("Eliminar a cor 'Vermelho'.\n");
}

void simularAtaque(Territorio* mapa, int o, int d) {

    if (o < 0 || o >= NUM_TERRITORIOS || d < 0 || d >= NUM_TERRITORIOS)
        return;

    printf("\nAtacando %s com tropas de %s...\n", mapa[d].nome, mapa[o].nome);

    if (mapa[o].tropas > mapa[d].tropas) {

        printf("Vitoria! %s conquistado.\n", mapa[d].nome);

        strcpy(mapa[d].dono, mapa[o].dono);

        mapa[d].tropas = 1;
        mapa[o].tropas--;
    }
    else {

        printf("Derrota! O ataque falhou.\n");

        mapa[o].tropas = 1;
    }
}

int verificarVitoria(const Territorio* mapa, int idMissao, const char* corJogador) {

    int contagem = 0;

    if (idMissao == MISSAO_CONQUISTA) {

        for (int i = 0; i < NUM_TERRITORIOS; i++) {

            if (strcmp(mapa[i].dono, corJogador) == 0)
                contagem++;
        }

        return (contagem >= 4);
    }
    else {

        for (int i = 0; i < NUM_TERRITORIOS; i++) {

            if (strcmp(mapa[i].dono, "Vermelho") == 0)
                return 0;
        }

        return 1;
    }
}

void liberarMemoria(Territorio* mapa) {

    free(mapa);
}

void limparBufferEntrada() {

    while (getchar() != '\n');
}