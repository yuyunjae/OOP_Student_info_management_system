#ifndef STUDENT_DB_H
# define STUDENT_DB_H

# include <string>
# include <iostream>
# include <vector>
# include <fstream>
# include <student.h>
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
    void sort_student_db();
    void parsing_student_info(string str);
    void insert_student(string name, string id, string department, string birth_year, string tel);
    void sort_student_db(int n);
    int compare_name(Student a, Student b);
    int compare_id(Student a, Student b);
    int compare_ad_year(Student a, Student b);
    int compare_dept(Student a, Student b);
    //select연산과 이를 통한 출력 구현하기
};

#endif