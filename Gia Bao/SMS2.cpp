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
    Score score,tmp;
    score.Input();
    Course Tmp;
    CSV_helper csv;
    if (csv.Get_details("course.txt",score.course_code,score.year,score.semester,Tmp)==0)
    {
        cout<<"This course does not exist!\n";
        return;
    }
    if (csv.Is_student_in_course(score.student_id,score.course_code,score.year,score.semester)==0)
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
        if (tmp.course_code==score.course_code && tmp.year==score.year && tmp.semester==score.semester && tmp.student_id==score.student_id && tmp.type==score.type)
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
