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
    std::cout << "1. Insertion\n";
    std::cout << "2. Search\n";
    std::cout << "3. Sorting Option\n";
    std::cout << "4. Exit\n";
}

void Menu::search_menu()
{
    std::cout << "- Search -\n";
    std::cout << "1. Search by name\n";
    std::cout << "2. Search by student ID (10 numbers)\n";
    std::cout << "3. Search by admission year (4 numbers)\n";
    std::cout << "4. Search by department name\n";
    std::cout << "5. List All\n";
}

void Menu::search_menu_option(int option)
{
    string opt;
    if (option == 1)
    {
        std::cout << "\nStudent name to search: ";
        std::getline(cin, opt);
        while (opt.size() < 1 || opt.size() > 15)
        {
            std::cout << "Please write student name with at least one character and up to 15 characters.\n";
            std::cout << "\nStudent name to search: ";
            std::getline(cin, opt);
        }
        db.search_student_name(opt);
    }
    else if (option == 2)
    {
        std::cout << "\nStudent ID to search: ";
        std::getline(cin, opt);
        while (opt.size() != 10 && atoi(opt.c_str()) && isdigit(opt.c_str()[0]))
        {
            std::cout << "Please write student ID exactly 10 digits.\n";
            std::cout << "\nStudent ID to search: ";
            std::getline(cin, opt);
        }
        db.search_student_id(opt);
    }
    else if (option == 3)
    {
        std::cout << "\nAdmission year to search: ";
        std::getline(cin, opt);
        while (opt.size() != 4 && atoi(opt.c_str()) && isdigit(opt.c_str()[0]))
        {
            std::cout << "Please write Admission year exactly 4 digits.\n";
            std::cout << "\nAdmission year to search: ";
            std::getline(cin, opt);
        }
        db.search_student_admin_year(opt);
    }
    else if (option == 4)
    {
        std::cout << "\nDepartment name to search: ";
        std::getline(cin, opt);
        db.search_student_dept_name(opt);
    }
}

int Menu::input_menu()
{
    int num_menu = 0;
    std::cout << "> ";
    std::cin >> num_menu;
    std::cin.ignore();
    return num_menu;
}

void Menu::insert_student_menu()
{
    string name; //up to 15 char
    string id; // first 4digits represent admission year; 10digit;
    string birth_year; //4digit
    string tel; //up to 12 digit
    string department;
    //student info
    std::cout << "\nName ? ";
    std::getline(cin, name);
    while (name.size() < 1 || name.size() > 15)
    {
        std::cout << "Please write student name with at least one character and up to 15 characters.\n";
        std::cout << "Name ? ";
        std::getline(cin, name);
    }
    std::cout << "Student ID (10 digits)? ";
    std::getline(cin, id);
    while (id.size() != 10 && atoi(id.c_str()) && isdigit(id.c_str()[0]))
    {
        std::cout << "Please write student ID exactly 10 digits.\n";
        std::cout << "Student ID (10 digits)? ";
        std::getline(cin, id);
    }
    std::cout << "Birth Year (4 digits) ? ";
    std::getline(cin, birth_year);
    while (birth_year.size() != 4 && atoi(birth_year.c_str()) && isdigit(birth_year.c_str()[0]))
    {
        std::cout << "Please write Birth Year exactly 4 digits.\n";
        std::cout << "Birth Year (4 digits) ? ";
        std::getline(cin, birth_year);
    }
    std::cout << "Department ? ";
    std::getline(cin, department);
    std::cout << "Tel ? ";
    std::getline(cin, tel);
    while (tel.size() != 4 && atoi(tel.c_str()) && isdigit(tel.c_str()[0]))
    {
        std::cout << "Please write Tel exactly 12 digits.\n";
        std::cout << "Tel ? ";
        std::getline(cin, tel);
    }
    //insert_student_info
    db.insert_student(name, id, department, birth_year, tel);
}

void Menu::sort_student_menu()
{
    std::cout << "-Sorting Option\n";
    std::cout << "1. Sort by Name\n";
    std::cout << "2. Sort by Student ID\n";
    std::cout << "3. Sort by Admission Year\n";
    std::cout << "4. Sort by Department name\n";
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
