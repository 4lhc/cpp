
#include <iostream>
#include <ncurses.h>


int main()
{

    initscr();

    char ch;
    noecho();
    while ((ch=getch()) != 27 )
    {
        mvprintw(10, 10, "%d = %c", ch, ch);
        move(0, 0);
    }
    printw("Hello World!");
    getch();
    endwin();
    return 0;
}
