#ifndef STUDENT_DB_H
# define STUDENT_DB_H

# include <string>
# include <iostream>
# include <vector>
# include <fstream>
# include <stdio.h>
# include "student.h"
# include <algorithm>

using namespace std;

class Student_db
{
private:
    vector<Student> student_list;
    string file_name;
public:
    Student_db();
    Student_db(string _file_name);
    void read_file();
    void write_file();
    void parsing_student_info(string str);
    void insert_student(string name, string id, string department, string birth_year, string tel);
    void sort_student_db(int n);
    void sort_student_db();
    static int compare_name(Student a, Student b);
    static int compare_id(Student a, Student b);
    static int compare_ad_year(Student a, Student b);
    static int compare_dept(Student a, Student b);
    int same_id_in_db(string s);
    void print_student_info_format();
    void print_student_info(Student s);
    void search_student_name(string s);
    void search_student_id(string s);
    void search_student_admin_year(string s);
    void search_student_dept_name(string s);
    void show_all_student_info();
};

#endif
