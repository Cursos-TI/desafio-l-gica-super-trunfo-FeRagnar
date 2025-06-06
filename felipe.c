#include <stdio.h>

int main() {
    // Dados da Carta 01
    char Estado[50], Codigodacarta[50], Nomedacidade[50];
    int Populacao, Numerodepontosturisticos;
    float Area, PIB, Densidade, PibPerCapita;

    // Dados da Carta 02
    char estado[50], codigodacarta[50], nomedacidade[50];
    int populacao, numerodepontosturisticos;
    float area, pib, densidade, pibpercapita;

    // Entrada de dados Carta 1
    printf("\nCarta 01\n");
    printf("Digite o nome do Estado: ");
    scanf(" %[^\n]s", Estado);
    printf("Digite o código da carta: ");
    scanf(" %[^\n]s", Codigodacarta);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", Nomedacidade);
    printf("Digite a população: ");
    scanf("%d", &Populacao);
    printf("Digite a área (km²): ");
    scanf("%f", &Area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &PIB);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &Numerodepontosturisticos);

    // Entrada de dados Carta 2
    printf("\nCarta 02\n");
    printf("Digite o nome do Estado: ");
    scanf(" %[^\n]s", estado);
    printf("Digite o código da carta: ");
    scanf(" %[^\n]s", codigodacarta);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", nomedacidade);
    printf("Digite a população: ");
    scanf("%d", &populacao);
    printf("Digite a área (km²): ");
    scanf("%f", &area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &numerodepontosturisticos);

    // Cálculos derivados
    Densidade = (float)Populacao / Area;
    PibPerCapita = (PIB * 1000000000) / Populacao;

    densidade = (float)populacao / area;
    pibpercapita = (pib * 1000000000) / populacao;

    int primeiroAtributo, segundoAtributo;

    // Função para exibir menu de atributos, omitindo um atributo se necessário
    void mostrarMenu(int omit) {
        printf("\n----- MENU DE ATRIBUTOS -----\n");
        if (omit != 1) printf("1 - População\n");
        if (omit != 2) printf("2 - Área\n");
        if (omit != 3) printf("3 - PIB\n");
        if (omit != 4) printf("4 - Pontos Turísticos\n");
        if (omit != 5) printf("5 - Densidade Demográfica\n");
        if (omit != 6) printf("6 - PIB per Capita\n");
    }

    // Escolha do primeiro atributo
    do {
        mostrarMenu(0);
        printf("Escolha o PRIMEIRO atributo para comparar (1-6): ");
        scanf("%d", &primeiroAtributo);
        if (primeiroAtributo < 1 || primeiroAtributo > 6)
            printf("Opção inválida. Tente novamente.\n");
    } while (primeiroAtributo < 1 || primeiroAtributo > 6);

    // Escolha do segundo atributo - não pode ser igual ao primeiro
    do {
        mostrarMenu(primeiroAtributo);
        printf("Escolha o SEGUNDO atributo para comparar (1-6), diferente do primeiro: ");
        scanf("%d", &segundoAtributo);
        if (segundoAtributo < 1 || segundoAtributo > 6 || segundoAtributo == primeiroAtributo)
            printf("Opção inválida ou igual ao primeiro atributo. Tente novamente.\n");
    } while (segundoAtributo < 1 || segundoAtributo > 6 || segundoAtributo == primeiroAtributo);

    // Função para obter valor do atributo de uma carta
    float getValorAtributo(int atributo, int popul, float area, float pib, int pontos, float dens, float pibpc) {
        switch (atributo) {
            case 1: return (float)popul;
            case 2: return area;
            case 3: return pib;
            case 4: return (float)pontos;
            case 5: return dens;
            case 6: return pibpc;
            default: return 0;
        }
    }

    // Função para obter nome do atributo
    const char* getNomeAtributo(int atributo) {
        switch (atributo) {
            case 1: return "População";
            case 2: return "Área";
            case 3: return "PIB";
            case 4: return "Pontos Turísticos";
            case 5: return "Densidade Demográfica";
            case 6: return "PIB per Capita";
            default: return "Desconhecido";
        }
    }

    // Função para decidir vencedor de um atributo (true se carta1 vence)
    int venceAtributo(int atributo, float val1, float val2) {
        if (atributo == 5) { // densidade: menor vence
            return val1 < val2 ? 1 : 0;
        } else { // maior vence
            return val1 > val2 ? 1 : 0;
        }
    }

    // Obtendo valores dos atributos para as duas cartas
    float val1_attr1 = getValorAtributo(primeiroAtributo, Populacao, Area, PIB, Numerodepontosturisticos, Densidade, PibPerCapita);
    float val2_attr1 = getValorAtributo(primeiroAtributo, populacao, area, pib, numerodepontosturisticos, densidade, pibpercapita);

    float val1_attr2 = getValorAtributo(segundoAtributo, Populacao, Area, PIB, Numerodepontosturisticos, Densidade, PibPerCapita);
    float val2_attr2 = getValorAtributo(segundoAtributo, populacao, area, pib, numerodepontosturisticos, densidade, pibpercapita);

    // Exibir resultado
    printf("\n--- Comparação entre %s e %s ---\n", Nomedacidade, nomedacidade);

    // Função para imprimir valores com formatação específica (int ou float)
    void printValor(int atributo, float valor) {
        if (atributo == 1 || atributo == 4) // atributos inteiros
            printf("%d", (int)valor);
        else if (atributo == 3) // PIB bilhões com 2 casas decimais
            printf("%.2f bilhões", valor);
        else if (atributo == 5) // densidade
            printf("%.2f hab/km²", valor);
        else if (atributo == 6) // PIB per capita reais
            printf("%.2f reais", valor);
        else // Área (float)
            printf("%.2f km²", valor);
    }

    // Mostrar atributos escolhidos e seus valores
    printf("\nAtributo 1: %s\n", getNomeAtributo(primeiroAtributo));
    printf("%s: ", Nomedacidade); printValor(primeiroAtributo, val1_attr1); printf("\n");
    printf("%s: ", nomedacidade); printValor(primeiroAtributo, val2_attr1); printf("\n");

    printf("\nAtributo 2: %s\n", getNomeAtributo(segundoAtributo));
    printf("%s: ", Nomedacidade); printValor(segundoAtributo, val1_attr2); printf("\n");
    printf("%s: ", nomedacidade); printValor(segundoAtributo, val2_attr2); printf("\n");

    // Decidir vencedor para cada atributo
    int vence1 = (val1_attr1 == val2_attr1) ? 0 : venceAtributo(primeiroAtributo, val1_attr1, val2_attr1);
    int vence2 = (val1_attr2 == val2_attr2) ? 0 : venceAtributo(segundoAtributo, val1_attr2, val2_attr2);

    // Somar valores para cada carta
    float soma1 = val1_attr1 + val1_attr2;
    float soma2 = val2_attr1 + val2_attr2;

    printf("\nSoma dos atributos:\n");
    printf("%s: ", Nomedacidade); printValor(primeiroAtributo, val1_attr1); printf(" + "); printValor(segundoAtributo, val1_attr2); printf(" = %.2f\n", soma1);
    printf("%s: ", nomedacidade); printValor(primeiroAtributo, val2_attr1); printf(" + "); printValor(segundoAtributo, val2_attr2); printf(" = %.2f\n", soma2);

    // Decidir vencedor final pela soma
    if (soma1 > soma2)
        printf("\nVencedora da rodada: %s\n", Nomedacidade);
    else if (soma2 > soma1)
        printf("\nVencedora da rodada: %s\n", nomedacidade);
    else
        printf("\nEmpate!\n");

    return 0;
}

