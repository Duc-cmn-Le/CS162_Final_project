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
