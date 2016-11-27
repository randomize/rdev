#include <assert.h>
#include <ncurses.h>

int main()
{
    int ch, count = 0;
    mmask_t old;

    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);

    while ((ch = getch()) != 'q') {
        count++;
        if (ch == KEY_MOUSE) {
            MEVENT event;
            assert(getmouse(&event) == OK);
            mvprintw(0, 0, "Mouse Event!\n");
        }
        mvprintw(1, 1, "Event number %4d", count);
        refresh();
    }
}
