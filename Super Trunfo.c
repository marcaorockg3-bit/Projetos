#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char estado1[3], estado2[3];         
    char codigo1[5], codigo2[5];         
    char cidade1[50], cidade2[50];

    int   populacaoc1, populacaoc2;
    float areac1, areac2;
    float pibc1, pibc2;                  
    int   pontosturisticosc1, pontosturisticosc2;

    float densidadepopulacionalc1, densidadepopulacionalc2;
    float pibpercapitac1, pibpercapitac2;
    float SuperPoderc1, SuperPoderc2;

    int opcao;

    int resultado1, resultado2;
    char PrimeiroAtributo, SegundoAtributo;
    int Ataque1, Ataque2, Defesa1, Defesa2, ContraAtaque1, ContraAtaque2;

    Ataque1 = (populacaoc1 + areac1);
    Ataque2 = (populacaoc2 + areac2);
    Defesa1 = (populacaoc1 + pibc1);
    Defesa2 = (populacaoc2 + pibc2);
    ContraAtaque1 = (populacaoc1+ SuperPoderc1);
    ContraAtaque1 = (populacaoc2 + SuperPoderc2);

        srand(time(0));
        Ataque1 = rand() % 100 + 1;
        Ataque2 = rand() % 100 + 1;
        Defesa1 = rand() % 100 + 1;
        Defesa2 = rand() % 100 + 1;
        ContraAtaque1 = rand() % 100 + 1;
        ContraAtaque2 = rand() % 100 + 1;

        
    printf("===== SUPER TRUNFO =====\n");

    printf("  ===*** FASE 1 ***===\n");

    
    printf("\n--- Carta 1 ---\n");
    printf("Estado: "); scanf(" %s", estado1);
    printf("Codigo: "); scanf(" %s", codigo1);
    printf("Cidade: "); scanf(" %49[^\n]", cidade1);
    printf("Populacao: "); scanf("%d", &populacaoc1);
    printf("Area: "); scanf("%f", &areac1);
    printf("PIB: "); scanf("%f", &pibc1);
    printf("Pontos turisticos: "); scanf("%d", &pontosturisticosc1);

    densidadepopulacionalc1 = (populacaoc1 / areac1);
    printf("Densidade Populacional: %.2f \n", densidadepopulacionalc1);
    
    pibpercapitac1 = (pibc1 / populacaoc1);
    printf("PIB per capita: %.2f \n", pibpercapitac1);
    
    SuperPoderc1 = (populacaoc1 + areac1 + pibc1 + pontosturisticosc1 + pibpercapitac1 + (1 / densidadepopulacionalc1));
    printf("Super Poder: %.2f", SuperPoderc1);
    
    printf("\n");
    

    printf("\n--- Carta 2 ---\n");
    printf("Estado: "); scanf(" %s", estado2);
    printf("Codigo: "); scanf(" %s", codigo2);
    printf("Cidade: "); scanf(" %49[^\n]", cidade2);
    printf("Populacao: "); scanf("%d", &populacaoc2);
    printf("Area: "); scanf("%f", &areac2);
    printf("PIB: "); scanf("%f", &pibc2);
    printf("Pontos turisticos: "); scanf("%d", &pontosturisticosc2);

    densidadepopulacionalc2 = (populacaoc2 / areac2);
    printf("Densidade Populacional: %.2f \n", densidadepopulacionalc2);
    
    pibpercapitac2 = (pibc2 / populacaoc2);
    printf("PIB per capita: %.2f \n", pibpercapitac2);
    
    SuperPoderc2 = (populacaoc2 + areac2 + pibc2 + pontosturisticosc2 + pibpercapitac2 + (1 / densidadepopulacionalc2));
    printf("Super Poder: %.2f \n", SuperPoderc2);
    
    printf("\n");

    
    printf("\n===== MENU DE COMPARACAO =====\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos turisticos\n");
    printf("5. Densidade demografica (vence o MENOR)\n");
    printf("6. PIB per Capita\n");
    printf("7. Super Poder\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);


    printf("  ===*** FASE 2 ***===\n");
    printf("\n===== RESULTADO =====\n");


    switch(opcao) {
        case 1: // População
            printf("Comparando População:\n");
            printf("%s: %d habitantes\n", cidade1, populacaoc1);
            printf("%s: %d habitantes\n", cidade2, populacaoc2);
            if (populacaoc1 > populacaoc2)  printf("Vencedora: %s\n", cidade1);
             else if (populacaoc2 > populacaoc1) printf("Vencedora: %s\n", cidade2);
             else printf("Empate!\n");
            break;

        case 2: // Área
            printf("Comparando Área:\n");
            printf("%s: %.2f km²\n", cidade1, areac1);
            printf("%s: %.2f km²\n", cidade2, areac2);
            if (areac1 > areac2) printf("Vencedora: %s\n", cidade1);
            else if (areac2 > areac1) printf("Vencedora: %s\n", cidade2);
            else printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Comparando PIB:\n");
            printf("%s: %.2f\n", cidade1, pibc1);
            printf("%s: %.2f\n", cidade2, pibc2);
            if (pibc1 > pibc2) printf("Vencedora: %s\n", cidade1);
            else if (pibc2 > pibc1) printf("Vencedora: %s\n", cidade2);
            else printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Comparando Pontos Turísticos:\n");
            printf("%s: %d\n", cidade1, pontosturisticosc1);
            printf("%s: %d\n", cidade2, pontosturisticosc2);
            if (pontosturisticosc1 > pontosturisticosc2) printf("Vencedora: %s\n", cidade1);
            else if (pontosturisticosc2 > pontosturisticosc1) printf("Vencedora: %s\n", cidade2);
            else printf("Empate!\n");
            break;

        case 5: // Densidade (menor vence)
            printf("Comparando Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", cidade1, densidadepopulacionalc1);
            printf("%s: %.2f hab/km²\n", cidade2, densidadepopulacionalc2);
            if (densidadepopulacionalc1 < densidadepopulacionalc2) printf("Vencedora: %s\n", cidade1);
            else if (densidadepopulacionalc2 < densidadepopulacionalc1) printf("Vencedora: %s\n", cidade2);
            else printf("Empate!\n");
            break;
            
        case 6: // PIB per Capita
            printf("Comparando PIB per Capita:\n");
            printf("%s: %.2f por habitantes\n", cidade1, pibpercapitac1);
            printf("%s: %.2f por habitantes\n", cidade2, pibpercapitac2);
            if (pibpercapitac1 > pibpercapitac2) printf("Vencedora: %s\n", cidade1);
            else if (pibpercapitac2 > pibpercapitac1) printf("Vencedora: %s\n", cidade2);
            else if (pibpercapitac1 == pibpercapitac2) printf("Empate!\n");
            
            break;
            
        case 7: // Super Poder
            printf("Comparando Super Poder:\n");
            printf("%s: %.2f\n", cidade1, SuperPoderc1);
            printf("%s: %.2f\n", cidade2, SuperPoderc2);
            if (SuperPoderc1 > SuperPoderc2) printf("Vencedora: %s \n", cidade1);
            else if (SuperPoderc2 > SuperPoderc1) printf("Vencedora: %s\n", cidade2);
            else if (SuperPoderc1 == SuperPoderc2) printf("Empate!\n");
            
            break;

        default:
            printf("Opcao invalida!\n");

            break;
    } 

    
    printf("\n===*** FASE 3 ***===\n");
    printf("    O Ataque Final\n");

    printf("Faça sua primeira escolha!\n");
    printf("A. Ataque\n");
    printf("D. Defesa\n");
    printf("C. Contra ataque\n");

    printf("Vamos ao combate!\n");
    scanf(" %c", &PrimeiroAtributo);

    switch (PrimeiroAtributo)
    {
    case 'A':
    case 'a':
        printf("Você escolheu atacar\n");
        resultado1 = Ataque1 > Ataque2 ? 1 : 0;

        break;

    case 'D':
    case 'd':
        printf("Você escolheu se defender\n");
        resultado1 = Defesa1 > Defesa2 ? 1 : 0;

        break;

    case 'C':
    case 'c':
        printf("Você escolheu Contra atacar\n");
        resultado1 = ContraAtaque1 > ContraAtaque2 ? 1 : 0;

        break;
    
    default:
        printf("Opção inválida!\n");
        break;
        
    }


    printf("\nFaça sua segunda escolha!\n");
    printf(" ***ATENÇÃO*** ");
    printf("Deve ser um atributo diferente do primeiro!\n");
    printf("A. Ataque\n");
    printf("D. Defesa\n");
    printf("C. Contra ataque\n");

    printf("Vamos ao combate!\n");
    scanf(" %c", &SegundoAtributo);

    if(PrimeiroAtributo == SegundoAtributo){
        printf("Você escolheu o mesmo atributo!\n");
    } else { 
        switch (SegundoAtributo){
    case 'A':
    case 'a':
        printf("Você escolheu atacar\n");
        resultado2 = Ataque1 > Ataque2 ? 1 : 0;

        break;

    case 'D':
    case 'd':
        printf("Você escolheu se defender\n");
        resultado2 = Defesa1 > Defesa2 ? 1 : 0;

        break;

    case 'C':
    case 'c':
        printf("Você escolheu Contra atacar\n");
        resultado2 = ContraAtaque1 > ContraAtaque2 ? 1 : 0;

        break;
    
    default:
        printf("Opção inválida!\n");
        break;
        
    }
    if(resultado1 && resultado2){
        printf("Parabéns, você venceu!\n");
    } else if (resultado1 != resultado2){
        printf("O jogo empatou!\n");
    } else {
        printf("Infelizmente, você perdeu!\n");
    }

}    

           

    return 0;
}