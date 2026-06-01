#include <stdio.h>
#include <windows.h>

void utf8_terminal();
void iniciar_menu();
void exibir_menu();
void menu_opcoes(int opcao);
int ler_int();
float ler_float();
void limpar_buffer();
void processar_dados();
void avaliar_temperatura(float temperatura);
void avaliar_energia(int energia);
void avaliar_comunicacao(int comunicacao);
int super_aquecimento(float temperatura);
int energia_baixa(int energia);
int falha_comunicacao(int comunicacao);
void exibir_relatorio_final(float temperatura, int energia, int comunicacao);

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
}

void menu_opcoes(int opcao) {
    switch (opcao)
    {
    case 1:
        processar_dados();
        break;

    case 2:
        break;

    case 3:
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
    float temperatura;
    int energia, comunicacao;

    printf("\nDigite a temperatura: ");
    temperatura = ler_float();

    printf("Digite a porcentagem de energia: ");
    energia = ler_int();

    printf("Digite o status da comunicação: ");
    comunicacao = ler_int();

    avaliar_temperatura(temperatura);

    avaliar_energia(energia);

    avaliar_comunicacao(comunicacao);

    exibir_relatorio_final(temperatura, energia, comunicacao);
}

void avaliar_temperatura(float temperatura) {
    if (super_aquecimento(temperatura)) {
        printf("Risco de superaquecimento!");
    }
}

void avaliar_energia(int energia) {
    if (energia_baixa(energia)) {
        printf("Ativar modo de economia de energia");
    }
}

void avaliar_comunicacao(int comunicacao) {
    if (falha_comunicacao(comunicacao)) {
        printf("Falha de comunicação");
    }
}

int super_aquecimento(float temperatura) {
    return temperatura > 80;
}

int energia_baixa(int energia) {
    return energia < 20;
}

int falha_comunicacao(int comunicacao) {
    return comunicacao == 0;
}

void exibir_relatorio_final(float temperatura, int energia, int comunicacao) {
    printf("\n\n==== RELATÓRIO FINAL ====\n");
    printf("Temperatura: %.2f °C\n", temperatura);
    printf("Energia: %d%%\n", energia);
    printf("Comunicação: %d%%\n", comunicacao);
}