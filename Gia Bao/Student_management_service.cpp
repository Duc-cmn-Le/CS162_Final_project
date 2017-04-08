#include "Student_management_service.h"
//course_code,year,semester,student_id,midterm,lab,final
void Student_management_service::Export_scores_of_student(const string username)
{
    ifstream f;
    f.open("score.txt");
    string s;
    int i,j;
    Score_list _list;
    Score tmp;
    while (!f.eof())
    {
        f>>s;
        i=s.find(',',s.find(',',s.find(',')+1)+1)+1;
        j=s.find(',',i);
        if (s.substr(i,j-i)==username)
        {
            i=s.find(',',++j);
            tmp.midterm=to_double(s.substr(j,i-j)); //Midterm
            j=s.find(',',++i);
            tmp.lab=to_double(s.substr(i,j-i)); //Lab
            i=s.find(',',++j);
            tmp._final=to_double(s.substr(j,i-j)); //Final
            i=s.find(',');
            tmp.course_code=s.substr(0,i); //Course code
            tmp.student_id=username; //Student ID
            j=s.find(',',++i);
            tmp.year=to_int(s.substr(i,j-i)); //Year
            i=s.find(',',++j);
            tmp.semester=to_int(s.substr(j,i-j)); //Semester
            _list.Add_to_last(tmp);
        }
    }
    f.close();
}
void Student_management_service::Export_scores_of_course(const string course_id)
{
    ifstream f;
    f.open("score.txt");
    string s;
    int i,j;
    Score_list _list;
    Score tmp;
    while (!f.eof())
    {
        f>>s;
        i=s.find(',');
        if (s.substr(0,i)==course_id)
        {
            tmp.course_code=course_id; //Course code
            j=s.find(',',++i);
            tmp.year=to_int(s.substr(i,j-i)); //Year
            i=s.find(',',++j);
            tmp.semester=to_int(s.substr(j,i-j)); //Semester
            j=s.find(',',++i);
            tmp.student_id=s.substr(i,j-i); //Student ID
            i=s.find(',',++j);
            tmp.midterm=to_double(s.substr(j,i-j)); //Midterm
            j=s.find(',',++i);
            tmp.lab=to_double(s.substr(i,j-i)); //Lab
            i=s.find(',',++j);
            tmp._final=to_double(s.substr(j,i-j)); //Final
            _list.Add_to_last(tmp);
        }
    }
    f.close();
}
//Ham k thuoc class
int to_int(const string s)
{
    int res=0;
    short i;
    for(i=0;i<s.size();i++) res=res*10+s[i]-48;
    return res;
}
double to_double(const string s)
{
    double res=0;
    short i;
    for(i=0;i<s.size();i++)
    if (s[i]!='.') res=res*10+s[i]-48;
    else break;
    if (i<s.size())
    {
        int tmp=1;
        for(i=i+1;i<s.size();i++)
        {
            tmp*=10;
            res+=double(s[i]-48)/tmp;
        }
    }
    return res;
}
