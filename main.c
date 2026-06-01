#include <stdio.h>
#include <windows.h>

void utf8_terminal();
void iniciar_menu();
void exibir_menu();
void menu_opcoes(int opcao);
int ler_int();
void limpar_buffer();

int main() {
    utf8_terminal();

    iniciar_menu();
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
        /* code */
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

void limpar_buffer() {
    while (getchar() != '\n');
}