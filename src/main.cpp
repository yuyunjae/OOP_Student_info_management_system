#include "menu.h"

int main(int argc, char **argv)
{
    if (argc == 2)
        Menu menual = Menu(argv[1]);
    else if (argc == 1)
        Menu menual = Menu();
    else return (1);
    menual.first_menu();
    return (0);
}
