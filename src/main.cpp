#include "menu.h"

int main(int argc, char **argv)
{
    if (argc == 2 || argc == 1)
    {
        Menu menual;
        if (argc == 2)
            menual = Menu(argv[1]);
        else
            menual = Menu();

        int sort_op = 1;
        int first_op = 0;
        while (true)
        {
            menual.first_menu();
            first_op = menual.input_menu();
            while (first_op < 1 || first_op > 4)
            {
                cout << "Please select the correct option.\n\n";
                first_op = menual.input_menu();
            }
            if (first_op == 4) //exit
            {
                menual.write_all(sort_op);
                return (0);
            }
            else if (first_op == 1) //insert
            {
                menual.insert_student_menu();
                menual.sort_student(sort_op);
            }
            else if (first_op == 2) //search
            {
                menual.search_menu();
                int opt = menual.input_menu();
                while (opt < 1 || opt > 5)
                {
                    cout << "Please select the correct option.\n\n";
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
                    cout << "Please select the correct option.\n\n";
                    sort_op = menual.input_menu();
                }
                menual.sort_student(sort_op);
            }
            cout << '\n';
        }
        return (0);
    }
    return (1);
}
