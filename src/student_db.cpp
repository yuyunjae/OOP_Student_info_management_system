#include <student_db.h>


Student_db::Student_db()
{
    file_name = "file1.txt";
    read_file();
    sort_student_db();
}

Student_db::Student_db(string _file_name)
{
    file_name = _file_name;
    read_file();
    sort_student_db();
}

void Student_db::insert_student(string name, string id, string department, string birth_year, string tel)
{
    Student stu = Student(name, id, department, birth_year, tel);
    student_list.push_back(stu);
}

void Student_db::parsing_student_info(string str)
{
    string element[5];
    int j = 0;
    int front = 0;
    for (int i=0; i < str.size(); i++)
    {
        if (str[i] == '?')
        {
            if (j == 5)
            {
                cout << "parsing error\n";
                break;
            }
            element[j++] = str.substr(front, i - front);
            front = i + 1; //front = &'?' + 1
        }
    }
    insert_student(element[0], element[1], element[2], element[3], element[4]);
}

void Student_db::read_file()
{
    string line;
    ifstream r_file(this->file_name);
    if (r_file.is_open())
    {
        while (getline(r_file, line))
            parsing_student_info(line);
        r_file.close();
    }
    else cout << "Unable to open file: " << this->file_name << "\n";
}

int Student_db::compare_name(Student a, Student b)
{
    // <연산이 되는지 모르겠음 compare 나 strcmp사용가능 여부 확인하기..
    return ((int)(a.get_name() < b.get_name()));
}

int Student_db::compare_id(Student a, Student b)
{
    return ((int)(a.get_id() < b.get_id()));
}
int Student_db::compare_ad_year(Student a, Student b)
{
    //고쳐야함 ad_year는 id의 앞 4글짜임.
    string s1 = a.get_id();
    string s2 = b.get_id();
    return ((int)(a.get_id() < b.get_id()));
}
int Student_db::compare_dept(Student a, Student b)
{
    return ((int)(a.get_department() < b.get_department()));
}

void Student_db::sort_student_db(int n) //1 name , 2 student id, 3 admission year, 4 department name;
{
    if (n == 1)
        sort(student_list.begin(), student_list.end(), compare_name);
    if (n == 2)
        sort(student_list.begin(), student_list.end(), compare_id);
    if (n == 3)
        sort(student_list.begin(), student_list.end(), compare_ad_year);
    if (n == 4)
        sort(student_list.begin(), student_list.end(), compare_dept);
}

void Student_db::write_file() //already sorted in menu
{
    ofstream o_file(this->file_name);
    if (o_file.is_open())
    {
        vector<Student>::iterator iter;
        for (iter = student_list.begin(); iter != student_list.end(); iter++)
        {
            o_file << iter->student_info() << '\n';
        }
        o_file.close();
    }
    else cout << "Unable to open file: " << this->file_name << "\n";
}

void Student_db::print_student_info()
{
    //
}
