#include "menu.h"

int main(int argc, char **argv)
{
    if (argc == 2)
        Menu menual = Menu(argv[1]);
    else if (argc == 1)
        Menu menual = Menu();
    else return (1);

    menual.first_menu();
    int sort_op = 1;
    int first_op = menual.input_menu();
    while (true)
    {
        while (first_op < 1 || first_op > 4)
        {
            cout << "Please select the correct option.\n\n";
            first_op = menual.input_menu();
        }
        if (first_op == 4)
            menual.write_all(sort_op);
        else if (first_op == 1)
        {
            menual.insert_student_menu();
        }
        else if (first_op == 2)
        else if (first_op == 3)
    }
    return (0);
}
