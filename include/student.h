#ifndef STUDENT_H
# define STUDENT_H
# include <string>
# include <iostream>

using namespace std;

class Student
{
private:
    string name; // up to 15 char
    string id; // first 4digits represent admission year; 10digit;
    string department;
    string birth_year; // 4digit
    string tel; // up to 12 digit

public:
    Student(string _name, string _id, string department, string _birth_year, string _tel);
    void change_name(string _name);
    void change_id(string _id);
    void change_department(string _department);
    void change_birth_year(string _birth_year);
    void change_tel(string _tel);
    string get_name();
    string get_id();
    string get_department();
    string get_birth_year();
    string get_tel();
    string student_info();
};

#endif
