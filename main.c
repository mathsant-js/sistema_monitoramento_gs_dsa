#include <stdio.h>
#include <windows.h>

void utf8_terminal();
void exibir_menu();

int main() {
    utf8_terminal();

    exibir_menu();
    return 0;
}

void utf8_terminal() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
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
        break;
    }
}