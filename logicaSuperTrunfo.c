#include <stdio.h>

int main() {
    // --- Declaração de Variáveis ---
    // Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePop1;
    float pibPerCapita1;

    // Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePop2;
    float pibPerCapita2;

    // Variáveis para a lógica de comparação
    int escolha1, escolha2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    int resultado1, resultado2; // 1 se Carta 1 vencer, 0 se Carta 2 vencer

    printf("=== Desafio Super Trunfo - Nível Mestre ===\n");

    // --- ENTRADA DE DADOS: CARTA 1 ---
    printf("\n-- Cadastro da Carta 1 --\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões): ");
    scanf("%f", &pib1);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- ENTRADA DE DADOS: CARTA 2 ---
    printf("\n-- Cadastro da Carta 2 --\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões): ");
    scanf("%f", &pib2);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- CÁLCULOS AUTOMÁTICOS ---
    densidadePop1 = (float)populacao1 / area1;
    pibPerCapita1 = pib1 * 1000000000 / (float)populacao1; // Ajuste para escala real
    
    densidadePop2 = (float)populacao2 / area2;
    pibPerCapita2 = pib2 * 1000000000 / (float)populacao2;

    // --- MENU INTERATIVO (Requisito: Switch) ---
    printf("\n=== Escolha os atributos para comparação ===\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Escolha o primeiro atributo (1-5): ");
    scanf("%d", &escolha1);
    
    printf("Escolha o segundo atributo (1-5): "); // Requisito Mestre: 2 atributos
    scanf("%d", &escolha2);

    printf("\n----------------------------------------\n");

    // --- LÓGICA DE SELEÇÃO 1 (Switch) ---
    switch (escolha1) {
        case 1: // População
            printf("Atributo 1: População\n");
            valor1_carta1 = (float)populacao1;
            valor1_carta2 = (float)populacao2;
            // Ternário: Se c1 > c2 retorna 1, senão 0
            resultado1 = (valor1_carta1 > valor1_carta2) ? 1 : 0; 
            break;
        case 2: // Área
            printf("Atributo 1: Área\n");
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            resultado1 = (valor1_carta1 > valor1_carta2) ? 1 : 0;
            break;
        case 3: // PIB
            printf("Atributo 1: PIB\n");
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            resultado1 = (valor1_carta1 > valor1_carta2) ? 1 : 0;
            break;
        case 4: // Pontos Turísticos
            printf("Atributo 1: Pontos Turísticos\n");
            valor1_carta1 = (float)pontosTuristicos1;
            valor1_carta2 = (float)pontosTuristicos2;
            resultado1 = (valor1_carta1 > valor1_carta2) ? 1 : 0;
            break;
        case 5: // Densidade (Regra Invertida!)
            printf("Atributo 1: Densidade Populacional\n");
            valor1_carta1 = densidadePop1;
            valor1_carta2 = densidadePop2;
            // Ternário invertido: Se c1 < c2 retorna 1 (vence), senão 0
            resultado1 = (valor1_carta1 < valor1_carta2) ? 1 : 0; 
            break;
        default:
            printf("Opção inválida para o atributo 1!\n");
            resultado1 = 0;
    }

    // Exibe resultado parcial 1
    printf("Carta 1: %.2f | Carta 2: %.2f -> Vencedor: %s\n", 
           valor1_carta1, valor1_carta2, resultado1 ? "Carta 1" : "Carta 2");

    printf("----------------------------------------\n");

    // --- LÓGICA DE SELEÇÃO 2 (Switch) ---
    switch (escolha2) {
        case 1: // População
            printf("Atributo 2: População\n");
            valor2_carta1 = (float)populacao1;
            valor2_carta2 = (float)populacao2;
            resultado2 = (valor2_carta1 > valor2_carta2) ? 1 : 0;
            break;
        case 2: // Área
            printf("Atributo 2: Área\n");
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            resultado2 = (valor2_carta1 > valor2_carta2) ? 1 : 0;
            break;
        case 3: // PIB
            printf("Atributo 2: PIB\n");
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            resultado2 = (valor2_carta1 > valor2_carta2) ? 1 : 0;
            break;
        case 4: // Pontos Turísticos
            printf("Atributo 2: Pontos Turísticos\n");
            valor2_carta1 = (float)pontosTuristicos1;
            valor2_carta2 = (float)pontosTuristicos2;
            resultado2 = (valor2_carta1 > valor2_carta2) ? 1 : 0;
            break;
        case 5: // Densidade (Regra Invertida!)
            printf("Atributo 2: Densidade Populacional\n");
            valor2_carta1 = densidadePop1;
            valor2_carta2 = densidadePop2;
            resultado2 = (valor2_carta1 < valor2_carta2) ? 1 : 0;
            break;
        default:
            printf("Opção inválida para o atributo 2!\n");
            resultado2 = 0;
    }

    // Exibe resultado parcial 2
    printf("Carta 1: %.2f | Carta 2: %.2f -> Vencedor: %s\n", 
           valor2_carta1, valor2_carta2, resultado2 ? "Carta 1" : "Carta 2");
    
    printf("----------------------------------------\n");

    // --- RESULTADO FINAL (Lógica de Pontuação) ---
    // Se a Carta 1 ganhou os dois (1 + 1 = 2) ou ganhou um e empatou...
    // Vamos usar uma soma simples: Quem tem mais vitórias vence.
    
    int pontuacao_carta1 = resultado1 + resultado2;
    int pontuacao_carta2 = (1 - resultado1) + (1 - resultado2);

    printf("\n=== RESULTADO FINAL ===\n");
    if (pontuacao_carta1 > pontuacao_carta2) {
        printf("A Carta 1 (%s) venceu a rodada!\n", nomeCidade1);
    } else if (pontuacao_carta2 > pontuacao_carta1) {
        printf("A Carta 2 (%s) venceu a rodada!\n", nomeCidade2);
    } else {
        printf("Houve um EMPATE!\n");
    }

    return 0;
}