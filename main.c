#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void utf8_terminal();
void iniciar_menu();
void exibir_menu();
void menu_opcoes(int opcao);
int ler_int();
float ler_float();
void limpar_buffer();
void processar_dados();
void avaliar_temperatura();
void avaliar_energia();
void avaliar_comunicacao();
int super_aquecimento(float temperatura);
int baixa_temperatura(float temperatura);
int energia_baixa(int energia);
int energia_abaixo_recomendavel(int energia);
int falha_comunicacao(int comunicacao);
int pouca_comunicacao(int comunicacao);
void exibir_status();
void avaliar_status();
void executar_analise();
void exibir_relatorio_final();
void exibir_historico();
void encerrar_programa();

#define MAX_LEITURAS 10

float historico_temperatura[MAX_LEITURAS];
int historico_energia[MAX_LEITURAS];
int historico_comunicacao[MAX_LEITURAS];

int total_leituras = 0;
float temperatura;
int energia, comunicacao;

int main() {
    utf8_terminal();

    while (1)
    {
        iniciar_menu();
    }
    
    return 0;
}

void utf8_terminal() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

void iniciar_menu() {
    int opcao;
    
    exibir_menu();

    opcao = ler_int();

    menu_opcoes(opcao);
}

void exibir_menu() {
    printf("\n==== SISTEMA DE MONITORAMENTO ====\n");
    printf("1 - Inserir Dados\n");
    printf("2 - Visualizar Status\n");
    printf("3 - Executar Análise\n");
    printf("4 - Histórico\n");
    printf("5 - Encerrar Sistema\n");
    printf("Digite uma opção: ");
}

void menu_opcoes(int opcao) {
    switch (opcao)
    {
    case 1:
        processar_dados();
        break;

    case 2:
        exibir_status();
        break;

    case 3:
        executar_analise();
        break;

    case 4:
        exibir_historico();
        break;

    case 5:
        encerrar_programa();
        break;
    default:
        printf("Opção inválida!");
        break;
    }
}

int ler_int() {
    int valor;

    while (scanf("%d", &valor) != 1)
    {
        printf("[ERRO]: Digite um inteiro válido: ");

        limpar_buffer();
    }

    limpar_buffer();

    return valor;
}

float ler_float() {
    float valor;

    while (scanf("%f", &valor) != 1)
    {
        printf("[ERRO]: Digite um número válido: ");

        limpar_buffer();
    }

    limpar_buffer();

    return valor;
}

void limpar_buffer() {
    while (getchar() != '\n');
}

void processar_dados() {
    printf("\nDigite a temperatura: ");
    temperatura = ler_float();

    do
    {
        printf("Digite a porcentagem de energia (0-100): ");
        energia = ler_int();
    } while (energia < 0 || energia > 100);

    do
    {
        printf("Digite a porcentagem da comunicação (0-100): ");
        comunicacao = ler_int();
    } while (comunicacao < 0 || comunicacao > 100);
    
    historico_temperatura[total_leituras] = temperatura;
    historico_energia[total_leituras] = energia;
    historico_comunicacao[total_leituras] = comunicacao;

    total_leituras++;

    printf("\nLeitura registrada com sucesso!\n");
}

void avaliar_temperatura() {
    if (super_aquecimento(temperatura)) {
        printf("TEMPERATURA: Risco de superaquecimento!");
    } 
    else if (baixa_temperatura(temperatura))
    {
        printf("TEMPERATURA: Risco de congelamento dos sistemas!");
    }
    else {
        printf("TEMPERATURA: Normal");
    }
}

void avaliar_energia() {
    if (energia_baixa(energia)) {
        printf("\nENERGIA: Ativar modo de economia de energia");
    }
    else if (energia_abaixo_recomendavel(energia))
    {
        printf("\nENERGIA: Abaixo do recomendável");
    }
    else {
        printf("\nENERGIA: Normal");
    }
}

void avaliar_comunicacao() {
    if (falha_comunicacao(comunicacao)) {
        printf("\nCOMUNICAÇÃO: Falha de comunicação\n");
    } 
    else if (pouca_comunicacao(comunicacao))
    {
        printf("\nCOMUNICACAÇÃO: Pouca comunicação\n");
    }
    else {
        printf("\nCOMUNICAÇÃO: normal\n");
    }
}

int super_aquecimento(float temperatura) {
    return temperatura > 80;
}

int baixa_temperatura(float temperatura) {
    return temperatura < 10;
}

int energia_baixa(int energia) {
    return energia < 20;
}

int energia_abaixo_recomendavel(int energia) {
    return energia < 40;
}

int falha_comunicacao(int comunicacao) {
    return comunicacao == 0;
}

int pouca_comunicacao(int comunicacao) {
    return comunicacao < 20;
}

void exibir_status() {
    avaliar_status();
}

void avaliar_status() {
    printf("\n==== STATUS ====\n");
    avaliar_temperatura();
    avaliar_energia();
    avaliar_comunicacao();
}

void executar_analise() {
    int riscos = 0;

    printf("\n==== ANÁLISE DA MISSÃO ====\n");

    printf("Temperatura atual: %.2f °C\n", temperatura);
    printf("Energia atual: %d%%\n", energia);
    printf("Comunicação atual: %d%%\n\n", comunicacao);

    if (super_aquecimento(temperatura)) {
        printf("[CRÍTICO] Superaquecimento\n");
        riscos += 2;
    }
    else if (baixa_temperatura(temperatura)) {
        printf("[ALERTA] Baixa temperatura\n");
        riscos++;
    }

    if (energia_baixa(energia)) {
        printf("[CRÍTICO] Energia crítica\n");
        riscos += 2;
    }
    else if (energia_abaixo_recomendavel(energia)) {
        printf("[ALERTA] Energia abaixo do recomendável\n");
        riscos++;
    }

    if (falha_comunicacao(comunicacao)) {
        printf("[CRÍTICO] Falha de comunicação\n");
        riscos += 2;
    }
    else if (pouca_comunicacao(comunicacao)) {
        printf("[ALERTA] Comunicação instável\n");
        riscos++;
    }

    printf("\nPontuação de risco: %d\n", riscos);

    if (riscos == 0) {
        printf("MISSÃO SEGURA\n");
    }
    else if (riscos <= 2) {
        printf("MISSÃO EM OBSERVAÇÃO\n");
    }
    else {
        printf("MISSÃO CRÍTICA\n");
    }
}

void exibir_relatorio_final() {
    printf("\n\n==== RELATÓRIO FINAL ====\n");
    printf("Temperatura: %.2f °C\n", temperatura);
    printf("Energia: %d%%\n", energia);
    printf("Comunicação: %d%%\n", comunicacao);
}

void exibir_historico() {

    int i;

    printf("\n==== HISTÓRICO ====\n");

    if (total_leituras == 0) {
        printf("Nenhuma leitura cadastrada.\n");
        return;
    }

    for(i = 0; i < total_leituras; i++) {

        printf("\nLeitura %d\n", i + 1);

        printf("Temperatura: %.2f °C\n",
               historico_temperatura[i]);

        printf("Energia: %d%%\n",
               historico_energia[i]);

        printf("Comunicação: %d%%\n",
               historico_comunicacao[i]);
    }
}

void encerrar_programa() {
    printf("\n\nPROGRAMA ENCERRADO\n\n");
    exit(0);
}