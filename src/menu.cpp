#include "menu.h"

Menu::Menu()
{
    db = Student_db("file1.txt");
}

Menu::Menu(string file_name)
{
    db = Student_db(file_name);
}

void Menu::first_menu()
{
    cout << "1. Insertion\n";
    cout << "2. Search\n";
    cout << "3. Sorting Option\n";
    cout << "4. Exit\n";
}

void Menu::search_menu()
{
    cout << "- Search -\n";
    cout << "1. Search by name\n";
    cout << "2. Search by student ID (10 numbers)\n";
    cout << "3. Search by admission year (4 numbers)\n";
    cout << "4. Search by department name\n";
    cout << "5. List All\n";
}

void Menu::search_menu_option(int option)
{
    string opt;
    if (option == 1)
    {
        cout << "Student name to search: ";
        getline(cin, opt);
        db.search_student_name(opt);
    }
    else if (option == 2)
    {
        cout << "Student ID to search: ";
        getline(cin, opt);
        db.search_student_id(opt);
    }
    else if (option == 3)
    {
        cout << "Admission year to search: ";
        getline(cin, opt);
        db.search_student_admin_year(opt);
    }
    else if (option == 4)
    {
        cout << "Department name to search: ";
        getline(cin, opt);
        db.search_student_dept_name(opt);
    }
}

int Menu::input_menu()
{
    int num_menu = 0;
    cout << "> ";
    getline(cin, num_menu);
    return num_menu;
}

void Menu::insert_student_menu()
{
    string name; //up to 15 char
    string id; // first 4digits represent admission year; 10digit;
    string birth_year; //4digit
    string tel; //up to 12 digit
    string department;
    //예외처리하기
    cout << "\nName ? ";
    getline(cin, name);
    while (name.size() < 1 || name.size() > 15)
        {
            cout << "Please write student name with at least one character and up to 15 characters.\n";
            cout << "Name ? ";
            getline(cin, name);
        }
    cout << "Student ID (10 digits)? ";
    getline(cin, id);
    while (id.size()!= 10)
        {
            cout << "Please write student ID exactly 10 digits.\n";
            cout << "Student ID (10 digits)? ";
            getline(cin, name);
        }
    cout << "Birth Year (4 digits) ? ";
    getline(cin, birth_year);
    cout << "Department ? ";
    getline(cin, department);
    cout << "Tel ? ";
    getline(cin, tel);
    db.insert_student(name, id, department, birth_year, tel);
}

void Menu::sort_student_menu()
{
    cout << "-Sorting Option\n";
    cout << "1. Sort by Name\n";
    cout << "2. Sort by Student ID\n";
    cout << "3. Sort by Admission Year\n";
    cout << "4. Sort by Department name\n";
}

void Menu::sort_student(int n)//1 name , 2 student id, 3 admission year, 4 department name;
{
    db.sort_student_db(n);
}

void Menu::write_all(int n)
{
    db.sort_student_db(n);
    db.write_file();
}
