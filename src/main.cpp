#include "menu.h"

int main(int argc, char **argv)
{
    Menu menual = Menu();
    if (argc == 2)
        Menu menual = Menu(argv[1]);
    else return (1);

    menual.first_menu();
    int sort_op = 1;
    int first_op = menual.input_menu();
    while (true)
    {
        while (first_op < 1 || first_op > 4)
        {
            cout << "Please select the correct option.\n";
            first_op = menual.input_menu();
        }
        if (first_op == 4) //exit
            menual.write_all(sort_op);
        else if (first_op == 1) //insert
        {
            menual.insert_student_menu();
        }
        else if (first_op == 2) //search
        {
            menual.search_menu();
            int opt = menual.input_menu();
            while (opt < 1 || opt > 5)
            {
                cout << "Please select the correct option.\n";
                opt = menual.input_menu();
            }
            menual.search_menu_option(opt);
        }
        else if (first_op == 3) //sort
        {
            menual.sort_student_menu();
            sort_op = menual.input_menu();
            while (sort_op < 1 || sort_op > 4)
            {
                cout << "Please select the correct option.\n";
                sort_op = menual.input_menu();
            } 
            menual.sort_student(sort_op);
        }
    }
    return (0);
}
