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
void encerrar_programa();

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
    printf("4 - Encerrar Sistema\n");
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

    printf("Digite a porcentagem de energia: ");
    energia = ler_int();

    printf("Digite o status da comunicação: ");
    comunicacao = ler_int();
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

    if (super_aquecimento(temperatura)) {
        printf("ALERTA: Superaquecimento\n");
        riscos += 2;
    } else if (baixa_temperatura(temperatura))
    {
        printf("ALERTA: Congelamento\n");
        riscos++;
    }

    if (energia_baixa(energia)) {
        printf("ALERTA: Energia crítica\n");
        riscos += 2;
    } else if (energia_abaixo_recomendavel(energia))
    {
        printf("ALERTA: Energia abaixo do recomendável\n");
        riscos++;
    }

    if (falha_comunicacao(comunicacao)) {
        printf("ALERTA: Falha de comunicação\n");
        riscos += 2;
    } else if (pouca_comunicacao(comunicacao))
    {
        printf("ALERTA: Pouca comunicação\n");
        riscos++;
    }

    printf("\nRiscos detectados: %d\n", riscos);

    if (riscos == 0) {
        printf("STATUS: OPERACIONAL\n");
    }
    else if (riscos < 5) {
        printf("STATUS: ATENÇÃO\n");
    }
    else {
        printf("STATUS: CRÍTICO\n");
    }
}

void exibir_relatorio_final() {
    printf("\n\n==== RELATÓRIO FINAL ====\n");
    printf("Temperatura: %.2f °C\n", temperatura);
    printf("Energia: %d%%\n", energia);
    printf("Comunicação: %d%%\n", comunicacao);
}

void encerrar_programa() {
    printf("\n\nPROGRAMA ENCERRADO\n\n");
    exit(0);
}