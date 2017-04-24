// Assign an existing class to a course
void Student_management_service::Assign_one_class()
{
    string tmp, class_code;
    cout << "Enter class code\n";
    cin >> class_code;
    Student_list a;
    a.List_all_student_of_class(class_code,tmp);
    if (a.Is_empty())
        cout << "There is no student in this class " << class_code << '\n';
    else {
        string course_code, year; int semester;
        cout << "Enter course code\n";
        cin >> course_code;
        cout << "Enter academic year\n";
        cin >> year;
        cout << "Enter semester\n";
        cin >> semester;
        filebuf fb, fbnew;
        fb.open ("course_student.txt",ios::in);
        fbnew.open ("course_student_new.txt",ios::out);
        istream fin(&fb);
        ostream fnew(&fbnew);
        string S, s;
        int c;
        while (getline(fin,S)) {
            c = Next_token(S,s);
            fnew << s << ",";
            if (s != course_code) {
                fnew << S << endl;
                continue;
            }
            c = Next_token(S,s);
            fnew << s << ",";
            if (s != year) {
                fnew << S << endl;
                continue;
            }
            c = Next_token(S,s);
            fnew << s;
            int tmp = 0;
            for (string::iterator i=s.begin();i!=s.end();++i)
                tmp = tmp*10 + *i - '0';
            if (tmp != semester) {
                fnew << "," << S << endl;
                continue;
            }
            fnew << "," << tmp << endl;
        }
        fb.close();
        fbnew.close();
        system("mv course_student_new.txt course_student.txt");
    }
}
