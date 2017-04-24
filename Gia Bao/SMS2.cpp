//course_code,year,semester,student_id,mark
void Student_management_service::Import_score() {
    cout<<"Enter type of score (0: midterm, 1: lab, 2: final): ";
    int type;
    cin>>type;
    cout<<"Enter name of data file: ";
    string s,p;
    cin.ignore();
    getline(cin,s);
    ifstream f;
    f.open(s);
    Score_list _list;
    Score tmp;
    while (getline(f,s))
    {
        Next_token(s,p);
        tmp.course_code=p;
        Next_token(s,p);
        tmp.year=to_int(p);
        Next_token(s,p);
        tmp.semester=to_int(p);
        Next_token(s,p);
        tmp.student_id=p;
        tmp.type=type;
        Next_token(s,p);
        tmp.mark=to_double(p);
        _list.Add_to_last(tmp);
    }
    f.close();
}

void Student_management_service::Edit_score()
{
    Score tmp;
    string course_code,year,student_id;
    int semester,type;
    double mark;
    cin.ignore();
    cout << "Course code:\n ";
    cin >> course_code;
    cout << "Year:\n ";
    cin >> year;
    cout << "Semester:\n ";
    cin >>  semester;
    cout << "Student ID:\n ";
    cin.ignore();
    cin >> student_id;
    cout << "Type:\n ";
    cin >> type;
    cout << "Mark:\n ";
    cin >> mark;
    Course Tmp;
    CSV_helper csv;
    if (csv.Get_details("course.txt",course_code,year,semester,Tmp)==0)
    {
        cout<<"This course does not exist!\n";
        return;
    }
    if (csv.Is_student_in_course(student_id,course_code,year,semester)==0)
    {
        cout<<"This student does not exist in this course!\n";
        return;
    }
    ifstream fi;
    ofstream fo;
    fi.open("score.txt");
    fo.open("score_new.txt");
    string s,p,q;
    while (getline(fi,q))
    {
        s=q;
        Next_token(s,p);
        tmp.course_code=p;
        Next_token(s,p);
        tmp.year=p;
        Next_token(s,p);
        tmp.semester=to_int(p);
        Next_token(s,p);
        tmp.student_id=p;
        Next_token(s,p);
        tmp.type=to_int(p);
        if (tmp.course_code==course_code && tmp.year==year && tmp.semester==semester && tmp.student_id==student_id && tmp.type==type)
        {
            q.erase(q.rfind(','));
            q+=s;
        }
        fo<<q<<'\n';
    }
    fi.close();
    fo.close();
    system("mv score_new.txt score.txt");
}

void Student_management_service::View_score_of(string student_id)
{
    string course_code,year;
    int semester;
    cin.ignore();
    cout<<"Enter course code: ";
    cin>>course_code;
    cout<<"Enter year: ";
    cin>>year;
    cout<<"Enter semester: ";
    cin>>semester;
    CSV_helper csv;
    Course Tmp;
    if (csv.Get_details("course.txt",course_code,year,semester,Tmp)==0)
    {
        cout<<"This course does not exist!\n";
        return;
    }
    if (csv.Is_student_in_course(student_id,course_code,year,semester)==0)
    {
        cout<<"This student does not exist in this course!\n";
        return;
    }
    ifstream f;
    f.open("score.txt");
    string s,p;
    string midterm="",lab="",_final="";
    Score tmp;
    while (getline(f,s))
    {
        Next_token(s,p);
        tmp.course_code=p;
        Next_token(s,p);
        tmp.year=p;
        Next_token(s,p);
        tmp.semester=to_int(p);
        Next_token(s,p);
        tmp.student_id=p;
        if (tmp.course_code==course_code && tmp.year==year && tmp.semester==semester && tmp.student_id==student_id)
        {
            Next_token(s,p);
            if (p=="0") midterm=s;
            else if (p=="1") lab=s;
            else _final=s;
            if (midterm!="" && lab!="" && _final!="") break;
        }
    }
    f.close();
    cout<<"Midterm: "<<midterm<<"\nLab: "<<lab<<"\nFinal: "<<_final<<'\n';
}
