#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void removerQuebraLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void lerString(char *msg, char *destino, int tamanho) {
    printf("%s", msg);
    fgets(destino, tamanho, stdin);
    removerQuebraLinha(destino);
}

int lerInteiroPositivo(char *msg) {
    char buffer[50];
    int valor;

    while (1) {
        printf("%s", msg);
        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%d", &valor) == 1 && valor >= 0) {
            return valor;
        }

        printf("Entrada inválida!\n");
    }
}

// Cadastro
void cadastrarTerritorios(Territorio *mapa, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n=== Território %d ===\n", i + 1);

        lerString("Nome: ", mapa[i].nome, 30);
        lerString("Cor do exército: ", mapa[i].cor, 10);
        mapa[i].tropas = lerInteiroPositivo("Quantidade de tropas: ");
    }
}

// Exibição
void exibirTerritorios(Territorio *mapa, int n) {
    printf("\n=== MAPA ATUAL ===\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] %s | Cor: %s | Tropas: %d\n",
               i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Ataque corrigido
void atacar(Territorio *atacante, Territorio *defensor) {

    // Não pode atacar se não tiver tropas
    if (atacante->tropas <= 0) {
        printf("❌ Este território não possui tropas para atacar!\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n🎲 Batalha!\n");
    printf("Atacante (%s) tirou: %d\n", atacante->nome, dadoAtacante);
    printf("Defensor (%s) tirou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("✅ O atacante venceu!\n");

        // Defensor perde 1 tropa
        if (defensor->tropas > 0) {
            defensor->tropas--;
        }

        // Se chegou a 0 → conquista
        if (defensor->tropas == 0) {
            printf("🏳️ Território conquistado!\n");

            // Muda a cor
            strcpy(defensor->cor, atacante->cor);

            // Transfere tropas
            int transferidas = atacante->tropas / 2;
            if (transferidas < 1) transferidas = 1;

            defensor->tropas = transferidas;
            atacante->tropas -= transferidas;
        }

    } else {
        printf("❌ O atacante perdeu!\n");

        // Atacante perde 1 tropa
        if (atacante->tropas > 0) {
            atacante->tropas--;
        }
    }
}

// Libera memória
void liberarMemoria(Territorio *mapa) {
    free(mapa);
}

int main() {
    int n;

    srand(time(NULL));

    printf("=== WAR - Sistema Final ===\n");

    n = lerInteiroPositivo("Digite o número de territórios: ");

    Territorio *mapa = (Territorio *) calloc(n, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro de memória!\n");
        return 1;
    }

    cadastrarTerritorios(mapa, n);

    int continuar = 1;

    while (continuar) {
        int atk, def;

        exibirTerritorios(mapa, n);

        printf("\n=== FASE DE ATAQUE ===\n");

        printf("Atacante: ");
        scanf("%d", &atk);

        printf("Defensor: ");
        scanf("%d", &def);

        getchar();

        // Validações
        if (atk < 0 || atk >= n || def < 0 || def >= n) {
            printf("Índices inválidos!\n");
            continue;
        }

        if (atk == def) {
            printf("Territórios iguais!\n");
            continue;
        }

        if (strcmp(mapa[atk].cor, mapa[def].cor) == 0) {
            printf("Mesma cor! Ataque inválido.\n");
            continue;
        }

        if (mapa[atk].tropas <= 0) {
            printf("Território atacante sem tropas!\n");
            continue;
        }

        atacar(&mapa[atk], &mapa[def]);

        exibirTerritorios(mapa, n);

        printf("\nContinuar? (1 = sim / 0 = não): ");
        scanf("%d", &continuar);
        getchar();
    }

    liberarMemoria(mapa);

    printf("\nFim do jogo!\n");

    return 0;
}