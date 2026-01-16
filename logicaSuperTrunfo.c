#include <stdio.h>
#include <string.h>

// Definição da estrutura da Carta
// Mantemos os tipos originais, mas faremos conversões (casting) para float na hora de comparar
typedef struct {
    char estado;
    char codigo[5];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
} Carta;

int main() {
    // --- 1. CADASTRO (Hardcoded para focar na lógica, conforme permitido) ---
    Carta c1 = {'A', "A01", "São Paulo", 12325000, 1521.11, 699.28, 50, 0};
    Carta c2 = {'B', "B01", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30, 0};

    // Calculamos a densidade agora para garantir que o dado existe
    c1.densidadePopulacional = (float)c1.populacao / c1.area;
    c2.densidadePopulacional = (float)c2.populacao / c2.area;

    // Variáveis para armazenar as escolhas e os valores convertidos
    int escolha1, escolha2;
    float valorA_c1, valorA_c2; // Valores do primeiro atributo
    float valorB_c1, valorB_c2; // Valores do segundo atributo
    char nomeAtributo1[30], nomeAtributo2[30];
    float soma_c1, soma_c2;

    printf("=== SUPER TRUNFO: NÍVEL MESTRE ===\n");
    printf("Duelo: %s vs %s\n\n", c1.nomeCidade, c2.nomeCidade);

    // --- 2. MENU DINÂMICO - PRIMEIRO ATRIBUTO ---
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Demográfica\n");
    printf("5. Pontos Turísticos\n");
    printf("Digite sua opção: ");
    scanf("%d", &escolha1);

    // Switch para pegar os valores da carta 1 e 2 baseados na escolha
    switch (escolha1) {
        case 1:
            valorA_c1 = (float)c1.populacao;
            valorA_c2 = (float)c2.populacao;
            strcpy(nomeAtributo1, "População");
            break;
        case 2:
            valorA_c1 = c1.area;
            valorA_c2 = c2.area;
            strcpy(nomeAtributo1, "Área");
            break;
        case 3:
            valorA_c1 = c1.pib;
            valorA_c2 = c2.pib;
            strcpy(nomeAtributo1, "PIB");
            break;
        case 4:
            valorA_c1 = c1.densidadePopulacional;
            valorA_c2 = c2.densidadePopulacional;
            strcpy(nomeAtributo1, "Densidade Demográfica");
            break;
        case 5:
            valorA_c1 = (float)c1.pontosTuristicos;
            valorA_c2 = (float)c2.pontosTuristicos;
            strcpy(nomeAtributo1, "Pontos Turísticos");
            break;
        default:
            printf("Opção inválida! Usando População por padrão.\n");
            valorA_c1 = (float)c1.populacao;
            valorA_c2 = (float)c2.populacao;
            strcpy(nomeAtributo1, "População");
            escolha1 = 1;
    }

    // --- 3. MENU DINÂMICO - SEGUNDO ATRIBUTO ---
    // Aqui está a lógica "Mestre": usamos IFs para NÃO mostrar a opção já escolhida
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    
    if (escolha1 != 1) printf("1. População\n");
    if (escolha1 != 2) printf("2. Área\n");
    if (escolha1 != 3) printf("3. PIB\n");
    if (escolha1 != 4) printf("4. Densidade Demográfica\n");
    if (escolha1 != 5) printf("5. Pontos Turísticos\n");
    printf("Digite sua opção: ");
    scanf("%d", &escolha2);

    // Validação extra: se o usuário for teimoso e digitar o mesmo número
    if (escolha1 == escolha2) {
        printf("\nERRO: Você escolheu o mesmo atributo! O sistema escolherá outro automaticamente.\n");
        // Lógica simples: se escolheu 1, muda pro 2. Se escolheu outro, muda pro 1.
        escolha2 = (escolha1 == 1) ? 2 : 1; 
    }

    // Switch para o segundo atributo
    switch (escolha2) {
        case 1:
            valorB_c1 = (float)c1.populacao;
            valorB_c2 = (float)c2.populacao;
            strcpy(nomeAtributo2, "População");
            break;
        case 2:
            valorB_c1 = c1.area;
            valorB_c2 = c2.area;
            strcpy(nomeAtributo2, "Área");
            break;
        case 3:
            valorB_c1 = c1.pib;
            valorB_c2 = c2.pib;
            strcpy(nomeAtributo2, "PIB");
            break;
        case 4:
            valorB_c1 = c1.densidadePopulacional;
            valorB_c2 = c2.densidadePopulacional;
            strcpy(nomeAtributo2, "Densidade Demográfica");
            break;
        case 5:
            valorB_c1 = (float)c1.pontosTuristicos;
            valorB_c2 = (float)c2.pontosTuristicos;
            strcpy(nomeAtributo2, "Pontos Turísticos");
            break;
        default:
            printf("Opção inválida! Considerando 0.\n");
            valorB_c1 = 0; valorB_c2 = 0;
    }

    // --- 4. CÁLCULO DA SOMA ---
    soma_c1 = valorA_c1 + valorB_c1;
    soma_c2 = valorA_c2 + valorB_c2;

    // --- 5. EXIBIÇÃO E LÓGICA DE VITÓRIA (COM TERNÁRIOS) ---
    printf("\n================ RESULTADOS ================\n");
    
    // Análise do Atributo 1
    printf("ATRIBUTO 1: %s\n", nomeAtributo1);
    printf("%s: %.2f | %s: %.2f\n", c1.nomeCidade, valorA_c1, c2.nomeCidade, valorA_c2);
    // Ternário especial: Se for densidade (4), menor vence. Senão, maior vence.
    int venceuA = (escolha1 == 4) ? (valorA_c1 < valorA_c2) : (valorA_c1 > valorA_c2);
    printf("Vencedor deste atributo: %s\n", venceuA ? c1.nomeCidade : c2.nomeCidade);
    printf("--------------------------------------------\n");

    // Análise do Atributo 2
    printf("ATRIBUTO 2: %s\n", nomeAtributo2);
    printf("%s: %.2f | %s: %.2f\n", c1.nomeCidade, valorB_c1, c2.nomeCidade, valorB_c2);
    int venceuB = (escolha2 == 4) ? (valorB_c1 < valorB_c2) : (valorB_c1 > valorB_c2);
    printf("Vencedor deste atributo: %s\n", venceuB ? c1.nomeCidade : c2.nomeCidade);
    printf("--------------------------------------------\n");

    // Resultado Final (Soma)
    printf("SOMA DOS ATRIBUTOS (Regra Final):\n");
    printf("%s: %.2f\n", c1.nomeCidade, soma_c1);
    printf("%s: %.2f\n", c2.nomeCidade, soma_c2);
    
    printf("\n>>> VENCEDOR GERAL: ");
    // Lógica para Empate e Vitória usando If/Else e Ternário
    if (soma_c1 == soma_c2) {
        printf("EMPATE!\n");
    } else {
        // Ternário: Se soma1 > soma2, imprime nome C1, senão nome C2
        printf("%s <<<\n", (soma_c1 > soma_c2) ? c1.nomeCidade : c2.nomeCidade);
    }
    printf("============================================\n");

    return 0;
}