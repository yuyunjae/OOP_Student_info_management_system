#include "student.h"

Student::Student(string _name, string _id, string _department, string _birth_year, string _tel)
{
    name = _name;
    id = _id;
    department = _department;
    birth_year = _birth_year;
    tel = _tel;
}

void Student::change_name(string _name)
{
    name = _name;
}

void Student::change_id(string _id)
{
    id = _id;
}

void Student::change_birth_year(string _birth_year)
{
    birth_year = _birth_year;
}

void Student::change_tel(string _tel)
{
    tel = _tel;
}

void Student::change_department(string _department)
{
    department = _department;
}

string Student::student_info()
{
    string info;
    info = name + "?" + id + "?" + department + "?" + birth_year + "?" + tel;
    return info;
}


string Student::get_name() {return name;}
string Student::get_id() {return id;}
string Student::get_department() {return department;}
string Student::get_birth_year() {return birth_year;}
string Student::get_tel() {return tel;}
