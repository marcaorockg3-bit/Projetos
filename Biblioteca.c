#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Constantes globais

#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100 // Define uma capacidade de emprestimos.
#define TAM_STRING 100


// --- Definição de Estruturas ---
// Struct livro agora tem um campo 'disponível' para controlar o status.

struct Livro {

    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para sim, 0 para não

};

// Nova struct para armazenar informações do empréstimo.
struct Emprestimo {

    int indiceLivro; // Pra saber qual livro do array "biblioteca" foi emprestado.
    char nomeUsuario[TAM_STRING];
};

// Função limpa buffer de entrada.
void limpaBufferdeEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ---Função Principal (main)
int main() {
// 1. ALOCAÇÃO DINAMICA DE MEMORIA
// Agora, em vez de arrays estaticos, usamos ponteiros.
struct Livro *biblioteca;
struct  Emprestimo *emprestimos;

//Usamos calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento).
// Vantagem: Inicia toda a memoria com zero. isso significa que 'disponivel' ja começa com 0
biblioteca = (struct Livro*) calloc (MAX_LIVROS, sizeof(struct Livro));

// Usamos malloc para  array de emprestimos. malloc(tamanho_total_em_bytes)
emprestimos = (struct Emprestimo* ) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

//VERIFICAÇÃO: É crucial verificar se a alocação de memoria deu certo.
if (biblioteca == NULL || emprestimos == NULL) {
    printf("Erro: Falha ao alocar memoria.\n");
    return 1; // retorna 1 para indicar o erro.
}

int totalLivros = 0;
int totalEmprestimos = 0;
int opcao;


do 
{
    printf("==============================\n");
    printf("     BIBLIOTECA - PARTE 2\n");
    printf("==============================\n");
    printf("1 - Cadastrar novo livro\n");
    printf("2 - Listar todos os livros\n");
    printf("3 - Realizar empréstimo\n");
    printf("4 - Listar empréstimos\n");
    printf("5 - Sair\n");
    printf("-------------------------------\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    limpaBufferdeEntrada();

    switch (opcao) {
        case 1: // Cadastro de livro
            printf(" --- Cadastro de Novo Livro ---\n\n");
            if (totalLivros < MAX_LIVROS) {
                // o acesso aos campos é igual ao array estático.
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
                printf("Digite o autor: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                printf("Digite a editora: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                
                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';
                
                printf("Digite a edição: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limpaBufferdeEntrada();


                // Ao cadastrar o livro, automaticamente se torna disponível.
                biblioteca[totalLivros].disponivel = 1;

                totalLivros++;
                printf("Livro cadastrado com sucesso!\n");             

            }else {
                printf("Biblioteca cheia!\n");
            }
            printf("\n pressione ENTER para continuar...");
            getchar();
            break;

        case 2: // LISTAGEM DE LIVROS
            printf(" --- Lista de livros cadastrados ---\n\n");
            if (totalLivros == 0) {
                printf("Nenhum livro cadastrado ainda!\n");
            } else {
                for (int i = 0; i < totalLivros; i++)
                {
                printf(" -----------------------------\n");
                printf("LIVRO %d\n", i + 1 );
                printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor: %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Edicao: %d\n", biblioteca[i].edicao);
                    printf("Status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Emprestado");
                }
                printf(" -----------------------------\n");

            }
            printf("\nPressione ENTER para continuar...");
            getchar();
            break;

        case 3: // REALIZAR EMPRÉSTIMO
            printf("--- Realizar Empréstimo ---\n");

            if (totalEmprestimos >= MAX_EMPRESTIMOS) 
            {
                printf("Limite de emprestimos atingido!\n");
            } else {
                printf("Livros disponiveis!\n");
                int disponiveis = 0;
                for (int i = 0; i < totalLivros; i++)
                {
                 if (biblioteca[i]. disponivel)
                 {
                    printf("%d - %s\n", i + 1,biblioteca[i]. nome);
                    disponiveis++;
                 }
                 
                }

                if (disponiveis == 0)
                {
                    printf("Nenhum livro didponivel para emprestimo!\n");
                } else {
                    printf("\nDigite o numero do livro que deseja emprestar: ");
                    int numLivro;
                    scanf("%d", &numLivro);
                    limpaBufferdeEntrada();

                    int indice = numLivro;

                    // validação da escolha do usuario.
                    if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel)
                    {
                        printf("Digite o nome do usuario que esta pegando o livro: ");
                        fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                        emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';

                        // registra o emprestimo.
                        emprestimos[totalEmprestimos].indiceLivro = indice;

                        // Atualiza o status do livro pra indisponivel.
                        biblioteca[indice].disponivel = 0;

                        totalEmprestimos++;
                        printf("\nEmprestimo realizado com sucesso!\n");

                    } else{
                        printf("\nNumero de livro invalido ou livro indisponivel.\n");
                    }
                    
                }
                
                
            }
            printf("\nPressione ENTER para continuar...");
            getchar();
            break;

        case 4: 
            printf("\n--- Lista de Emprestimos ---\n");

            if (totalEmprestimos == 0) {
                printf("Nenhum emprestimo registrado.\n");
            } else {
                for (int i = 0; i < totalEmprestimos; i++){
                    
                    int indiceLivro = emprestimos[i].indiceLivro;
                    printf("------------------------------\n");
                    printf("EMPRESTIMO %d\n", i + 1);
                    printf("livro: %s\n", biblioteca[indiceLivro].nome);
                    printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
                }
                printf("----------------------------\n");
            }
            printf("\nPressione ENTER para continuar...");
            getchar();
            break;


        case 5:
            printf("\nSaindo do siatema...\n");
            break;
         
         default:
            printf("\nOpcao invalida!\n");
            printf("\nPressione ENTER para continuar... ");
            getchar();
            break;   




    }  
} while (opcao != 0);

// 2. LIBERAÇÃO DA MEMÓRIA
// Antes de terminar, é essencial liberar a memoria que foi alocada dinamicamente.
// Isso evita "memory leaks"(vazamento de memoria).

free(biblioteca);
free(emprestimos);

printf("Memoria liberada com sucesso!\n");

return 0;

}


