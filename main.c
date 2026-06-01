#include <stdio.h>
#include <windows.h>

void utf8_terminal();
void menu();

int main() {
    utf8_terminal();

    menu();
    return 0;
}

void utf8_terminal() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

void menu() {
    printf("\n==== SISTEMA DE MONITORAMENTO ====\n");
    printf("1 - Inserir Dados\n");
    printf("2 - Visualizar Status\n");
    printf("3 - Executar Análise\n");
    printf("4 - Encerrar Sistema\n");
}