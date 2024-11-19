#include <ncurses.h>

int main()
{
    // Inicializa o modo ncurses
    initscr();
    // Configura o terminal para não mostrar a entrada do usuário
    noecho();
    // Habilita a leitura de teclas especiais (como F1, setas)
    keypad(stdscr, TRUE);

    // Escreve uma mensagem na tela
    printw("Hello, ncurses!");
    // Atualiza a tela para mostrar o texto
    refresh();

    // Aguarda o usuário pressionar uma tecla
    getch();

    // Finaliza o modo ncurses
    endwin();

    return 0;
}
