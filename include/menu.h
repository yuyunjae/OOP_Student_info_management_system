#ifndef MENU_H
# define MENU_H
# include <string>
# include <iostream>
# include "student_db.h"

using namespace std;

class Menu
{
private:
    Student_db db;
public:
    Menu();
    Menu(string file_name);

    void first_menu();
    void search_menu();
    int input_menu();
    void insert_student_menu();
    void sort_student_menu();
    void sort_student();
    void sort_student(int n);
    void write_all(int n);
};

#endif