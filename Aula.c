#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;

} pessoa;

int main(){

    pessoa* p = (pessoa*)malloc(sizeof(pessoa));
    
    printf("Digite o nome: ");
    scanf("%s", p->nome);

    printf("Digite a idade: ");
    scanf("%d", &p->idade);

    printf("%s tem %d anos.\n", p->nome, p->idade);

    free(p);

    return 0;
    
}
