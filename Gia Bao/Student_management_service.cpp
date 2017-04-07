#include "Student_management_service.h"
//course_code,year,semester,student_id,midterm,lab,final
void Student_management_service::Export_scores_of_student(const string username)
{
    ifstream f;
    f.open("score.txt");
    string s;
    int i,j;
    bool exist=false;
    while (!f.eof())
    {
        f>>s;
        i=s.find(',',s.find(',',s.find(',')+1)+1)+1;
        j=s.find(',',i);
        if (s.substr(i,j-i)==username)
        {
            cout<<"Course code: "<<s.substr(0,s.find(','));
            cout<<"\nMidterm: ";
            for(i=j+1;s[i]!=',';i++) cout<<s[i];
            cout<<"\nLab: ";
            for(j=i+1;s[j]!=',';j++) cout<<s[j];
            cout<<"\nFinal: ";
            for(i=j+1;i<s.size();i++) cout<<s[i];
            cout<<"\n\n";
            exist=true;
        }
    }
    f.close();
    if (!exist) cout<<"This student is not found!\n\n";
}
void Student_management_service::Export_scores_of_course(const string course_id)
{
    ifstream f;
    f.open("score.txt");
    string s;
    int i,j;
    bool exist=false;
    while (!f.eof())
    {
        f>>s;
        if (s.substr(0,s.find(','))==course_id)
        {
            cout<<"Student ID: ";
            i=s.find(',',s.find(',',s.find(',')+1)+1)+1;
            for(j=i;s[j]!=',';j++) cout<<s[j];
            cout<<"\nMidterm: ";
            for(i=j+1;s[i]!=',';i++) cout<<s[i];
            cout<<"\nLab: ";
            for(j=i+1;s[j]!=',';j++) cout<<s[j];
            cout<<"\nFinal: ";
            for(i=j+1;i<s.size();i++) cout<<s[i];
            cout<<"\n\n";
            exist=true;
        }
    }
    f.close();
    if (!exist) cout<<"This course is not found!\n\n";
}
