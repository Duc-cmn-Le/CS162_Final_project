#include "SMS.h"

/// Other function

// Gia Bao
int to_int(const string s)
{
    int res=0;
    short i;
    for(i=0;i<s.size();i++) res=res*10+s[i]-48;
    return res;
}

// Gia Bao
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

// Mai Trinh
int Check_in_date(Date d, Course c) {
    Date s = c.start_at, e = c.end_at;
    if (s.y < d.y && d.y < e.y) return 1;
    if (s.y == d.y && d.y != e.y) {
        if (s.m < d.m) return 1;
        if (s.m != d.m) return 0;
        if (s.d < d.d) return 1;
        if (s.d != d.d) return 0;
        return 1;
    }
    if (e.y == d.y && d.y != s.y) {
        if (d.m < e.m) return 1;
        if (d.m != e.m) return 0;
        if (d.d < e.d) return 1;
        if (d.d != e.d) return 0;
        return 1;
    }
    if (s.y == e.y && s.y == d.y) {
        if (s.m < d.m && d.m < e.m) return 1;
        if (s.m == d.m && d.m != e.m) {
            if (s.d < d.d) return 1;
            if (s.d != d.d) return 0;
            return 1;
        }
        if (e.m == d.m && d.m != s.m) {
            if (d.d < e.d) return 1;
            if (d.d != e.d) return 0;
            return 1;
        }
        if (s.m == e.m && d.m == e.m) {
            if (s.d <= d.d && d.d <= e.d) return 1;
            return 0;
        }
    }
    return 0;
}

// Mai Trinh
int Check_in_time(Time d, Course c) {
    Time s = c.from, e = c.to;
    if (s.h < d.h && d.h < e.h) return 1;
    if (s.h == d.h && d.h != e.h) {
        if (s.m < d.m) return 1;
        if (s.m != d.m) return 0;
        if (s.s < d.s) return 1;
        if (s.s != d.s) return 0;
        return 1;
    }
    if (e.h == d.h && d.h != s.h) {
        if (d.m < e.m) return 1;
        if (d.m != e.m) return 0;
        if (d.s < e.s) return 1;
        if (d.s != e.s) return 0;
        return 1;
    }
    if (s.h == e.h && s.h == d.h) {
        if (s.m < d.m && d.m < e.m) return 1;
        if (s.m == d.m && d.m != e.m) {
            if (s.s < d.s) return 1;
            if (s.s != d.s) return 0;
            return 1;
        }
        if (e.m == d.m && d.m != s.m) {
            if (d.s < e.s) return 1;
            if (d.s != e.s) return 0;
            return 1;
        }
        if (s.m == e.m && d.m == e.m) {
            if (s.s <= d.s && d.s <= e.s) return 1;
            return 0;
        }
    }
    return 0;
}

// Mai Trinh
void Take_time(Date &d, Time &t, string &wday) {
    time_t tme;
    time(&tme);
    tm *cur;
    cur = localtime(&tme);
    string S = asctime(cur);
    string s;
    Next_token(S,s,' ');
    switch (s[2]) {
        case 'n':
            if (s[1] == 'u') wday = "Sunday";
            else wday = "Monday";
            break;
        case 'e':
            wday = "Tuesday";
            break;
        case 'd':
            wday = "Wednesday";
            break;
        case 'u':
            wday = "Thursday";
            break;
        case 'i':
            wday = "Friday";
            break;
        case 't':
            wday = "Saturday";
    }
    Next_token(S,s,' ');
    switch (s[2]) {
        case 'r':
            if (s[1] == 'a') d.m = 3;
            else d.m = 4;
            break;
        case 'n':
            if (s[1] == 'a') d.m = 1;
            else d.m = 6;
            break;
        case 'b':
            d.m = 2;
            break;
        case 'y':
            d.m = 5;
            break;
        case 'l':
            d.m = 7;
            break;
        case 'g':
            d.m = 8;
            break;
        case 'p':
            d.m = 9;
            break;
        case 't':
            d.m = 10;
            break;
        case 'v':
            d.m = 11;
            break;
        case 'c':
            d.m = 12;
            break;
    }
    Next_token(S,s,' ');
    d.d = (s[0]-'0')*10 + s[1] - '0';
    Next_token(S,s,' ');
    t.h = (s[0]-'0')*10 + s[1] - '0';
    t.m = (s[3]-'0')*10 + s[4] - '0';
    t.s = (s[6]-'0')*10 + s[7] - '0';
    Next_token(S,s,' ');
    d.y = 0;
    S.erase(S.length()-1,S.length()-1);
    for (string::iterator i=S.begin();i!=S.end();++i)
        d.y = d.y*10 + int(char(*i)) - '0';
}

// Import courses - Cong Duc
void Student_management_service::Import_course() {
    Course_list a;
    cout << "Enter number of course\n";
    int number;
    cin >> number;
    for (;number;number--) 
        a.Add_a_course();
    CSV_helper Helper;
    Helper.Write_file(a,"course.txt");
}

// Import course from file - Cong Duc
void Student_management_service::Import_course_from_file() {
    cout << "Enter file name (name.csv - with no space)\n";
    string file_name;
    cin >> file_name;
        CSV_helper Helper;
        Helper.CSV_reform(file_name);
    ifstream fin(file_name.c_str());
    Course_list a;
    a.Input_line_by_line(fin);
    fin.close();
    Helper.Write_file(a,"course.txt");
}

//Import student list - Cong Duc
void Student_management_service::Import_student_list() {
    Student_list a;
    cout << "Enter number of student\n";
    int number;
    cin >> number;
    for (;number;number--) 
        a.Add_student_to_last();
    CSV_helper Helper;
    Helper.Write_file(a,"user.txt");
}



// Import class from file - Cong Duc
void Student_management_service::Import_class_from_file() 
{ 
    string class_code;
    cout << "Enter class code\n";
    cin >> class_code;
    cin.ignore();
    cout << "Enter file name (name.csv)\n";
    string file_name;
    getline(cin,file_name);
        CSV_helper Helper;
        Helper.CSV_reform(file_name);
    ifstream fin(file_name.c_str());
    Student_list a;
    a.Input_line_by_line(fin);
    fin.close();
    Helper.Write_file(a,"user.txt");
    cout << "Imported class from file to database system\n";
    cout << "Each student has an account with username and password is student ID\n";
}

//Import scores - Cong Duc
void Student_management_service::Import_score() { 
    Score_list a;
    int number;
    cout << "Enter number of score\n";
    cin >> number;
    for (;number;number--)
        a.Add_score_to_last();
    CSV_helper Helper;
    Helper.Write_file(a,"score.txt");
}

// Import score from file - Cong Duc
void Student_management_service::Import_score_from_file() 
{
    int type, semester;
    cout << "What is type of exam (0 - Midterm, 1 - Lab, 2 - Final)\n";
    cin >> type;
    string file_name, course_code, year;
    cout << "Enter course name\n";
    cin >> course_code;
    cout << "Enter academic year\n";
    cin >> year;
    cout << "Enter semester\n";
    cin >> semester;
        CSV_helper Helper;
    Course _course;
    if (Helper.Get_details("course.txt",course_code,year,semester,_course) == 0) {
        cout << "This course is not found in system database\n";
        return;
    }
    cout << "Enter file name (name.csv)\n";
    cin >> file_name;
        Helper.CSV_reform(file_name);
    ifstream fin(file_name.c_str());
    // CS161,2016,1,1651005,10
    // fout: CS161,2016,1,1651005,type,10
    string S, s;
    Score tmp;
    tmp.course_code = course_code;
    tmp.year = year;
    tmp.semester = semester;
    tmp.type = type;
    Score_list a;
    while (getline(fin,S)) {
        Next_token(S,s);
        if (s[0] < '0' || s[0] > '9') continue;
        tmp.student_id = s;
        tmp.mark = to_double(S);
        a.Add_to_last(tmp);
    }
    fin.close();
    Helper.Write_file(a,"score.txt");
}

// Add an existing student to a course - Mai Trinh
void Student_management_service::Assign_one_student() 
{
    string course_code, year, student_id;
    int semester;
    cout << "Enter course code\n";
    cin >> course_code;
    cout << "Enter academic year\n";
    cin >> year;
    cout << "Enter semester\n";
    cin >> semester;
    cout << "Enter student ID\n";
    cin >> student_id;
    CSV_helper Helper; User tmp;
    if (Helper.Get_details("user.txt",student_id,tmp) == 0) 
        cout << "No student with ID " << student_id << " in system\n";
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
        while (Next_token(S,s)) {
            fnew << "," << s;
            if (s == student_id) {
                cout << "Student with ID " << student_id << " is already in this course\n";
                fbnew.close();
                system("rm course_student_new.txt");
            }
        }
        fnew << "," << S << "," << student_id << endl;
    }
    fb.close();
    fbnew.close();
    system("mv course_student_new.txt course_student.txt");
    cout << "Assigned student with ID " << student_id << " to this course\n";
    return;
}

// Assign an existing class to a course - Cong Duc
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
        // - Processing
        CSV_helper Helper; Course c;
        if (Helper.Get_details("course.txt",course_code,year,semester,c) == 0) {
            cout << "Course code " << course_code << " not found\n";
            return;
        }
        filebuf fb, fbnew;
        fb.open ("course_student.txt",ios::in);
        fbnew.open ("course_student_new.txt",ios::out);
        istream fin(&fb);
        ostream fnew(&fbnew);
        string S, s;
        while (getline(fin,S)) {
            Next_token(S,s);
            fnew << s << ",";
            if (s != course_code) {
                fnew << S << endl;
                continue;
            }
            Next_token(S,s);
            fnew << s << ",";
            if (s != year) {
                fnew << S << endl;
                continue;
            }
            Next_token(S,s);
            fnew << s;
            int t = 0;
            for (string::iterator i=s.begin();i!=s.end();++i)
                t = t*10 + *i - '0';
            if (t != semester) {
                fnew << "," << S << endl;
                continue;
            }
            fnew << "," << S << ',' << tmp << endl;
        }
        fb.close();
        fbnew.close();
        system("mv course_student_new.txt course_student.txt");
    }
}

// Show list of student in class - Cong Duc
void Student_management_service::Show_list_of_student_in_class() 
{
    string class_code, s;
    cout << "Enter class code\n";
    cin >> class_code;
    Student_list a;
    a.List_all_student_of_class(class_code, s);
    if (a.Is_empty())
        cout << "There is no student in class " << class_code << '\n';
    else a.Print_list(cout);
}

// Show list of student in course - Cong Duc
void Student_management_service::Show_list_of_student_in_course() 
{
    string course_code, year; int semester;
    cout << "Enter course code\n";
    cin >> course_code;
    cout << "Enter year\n";
    cin >> year;
    cout << "Enter semester\n";
    cin >> semester;
    Student_list a;
    string tmp;
    a.List_all_student_of_course(course_code,year,semester,tmp);
    if (a.Is_empty())
        cout << "There is still no student in this course\n";
    else a.Print_list(cout);
}

// View list of course - Mai Trinh
void Student_management_service::View_list_of_course() {
    string S, s;
    Course c;
    Course_list a;
    filebuf fb;
    fb.open ("course.txt",ios::in);
    istream fin(&fb);
    while (getline(fin,S)) {
        _Next__token(S,s);
        c.course_code = s;
        _Next__token(S,s);
        c.year = s;
        _Next__token(S,s);
        c.semester = int(s[0])-48;
        _Next__token(S,s);
        c.course_name = s;
        _Next__token(S,s);
        c.lecturer_name = s;
        _Next__token(S,s);
        Date_process(s,c.start_at);
        _Next__token(S,s);
        Date_process(s,c.end_at);
        _Next__token(S,s);
        Time_process(s,c.from);
        _Next__token(S,s);
        Time_process(s,c.to);
        c.date_of_week = S;
        a.Add_tail(c);
    }
    a.Print_list(cout);
    fb.close();
}

// Edit score - Gia Bao

void Student_management_service::Edit_score()
{
    string course_code, year, student_id; int semester, type; double mark;
    cout << "Enter course code\n";
    cin >> course_code;
    cout << "Enter year\n";
    cin >> year;
    cout << "Enter semester\n";
    cin >> semester;
    CSV_helper csv;
    Course Tmp;
    if (csv.Get_details("course.txt",course_code,year,semester,Tmp)==0)
    {
        cout<<"This course does not exist!\n";
        return;
    }
    cout << "Enter type of exam (0 - midterm, 1 - lab, 2 - final)\n";
    cin >> type;
    cout << "Enter student ID\n";
    cin >> student_id;
    if (csv.Is_student_in_course(student_id,course_code,year,semester)==0)
    {
        cout<<"This student does not attend to in this course!\n";
        return;
    }
    cout << "Enter new mark\n";
    cin >> mark;
    ifstream fi;
    ofstream fo;
    fi.open("score.txt");
    fo.open("score_new.txt");
    string s,p,q;
    while (getline(fi,s))
    {
        Next_token(s,p);
        fo << p << ',';
        if (p != course_code) {fo << s << '\n'; continue;}
        Next_token(s,p);
        fo << p << ',';
        if (p != year) {fo << s << '\n'; continue;}
        Next_token(s,p);
        fo << p << ',';
        if (to_int(p) != semester) {fo << s << '\n'; continue;}
        Next_token(s,p);
        fo << p << ',';
        if (p != student_id) {fo << s << '\n'; continue;}
        Next_token(s,p);
        fo << p << ',';
        if (to_int(p) != type) {fo << s << '\n'; continue;}
        fo << mark << '\n';
        
    }
    fi.close();
    fo.close();
    system("mv score_new.txt score.txt");
}

// View score of a student - Gia Bao
void Student_management_service::View_score_of(string student_id)
{
    string course_code,year;
    int semester;
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
        cout<<"This student does not attend to this course!\n";
        return;
    }
    ifstream f;
    f.open("score.txt");
    string s,p;
    string midterm="0",lab="0",_final="0";
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
//            if (midterm!="" && lab!="" && _final!="") break;
        }
    }
    f.close();
    cout<<"Midterm: "<<midterm<<"\nLab: "<<lab<<"\nFinal: "<<_final<<'\n';
}

// Export score of course - Gia Bao
void Student_management_service::Export_score_of_course(ostream &fout) 
{
    string course_code, year; int semester, type;
    Score sc;
    cout << "Enter course code\n";
    cin >> sc.course_code;
    cout << "Enter academic year\n";
    cin >> sc.year;
    cout << "Enter semester\n";
    cin >> sc.semester;
        Course tmp;
        CSV_helper Helper;
    if (Helper.Get_details("course.txt",sc.course_code,sc.year,sc.semester,tmp) == 0) {
        cout << "This course does not exist in system database\n";
        return;
    }
    cout << "Enter type of exam (0 - midterm, 1 - lab, 2 - final)\n";
    cin >> sc.type;
    ifstream fin("score.txt");
    string S, s, _tmp;
    Score_list a;
    Student_list b; 
    while (getline(fin,S)) {
        Next_token(S,s);
        if (s != sc.course_code) continue;
        Next_token(S,s);
        if (s != sc.year) continue;
        Next_token(S,s);
        if (to_int(s) != sc.semester) continue;
        Next_token(S,sc.student_id);
        Next_token(S,s);
        if (to_int(s) != sc.type) continue;
        sc.mark = to_double(S);
        a.Add_to_last(sc);
    }
    fin.close();
        b.List_all_student_of_course(sc.course_code,sc.year,sc.semester,_tmp);
        _tmp += ',';
        while (Next_token(_tmp,s)) 
            if (a.Find_student(s) == 0) {   
                sc.mark = 0;
                sc.student_id = s;
                a.Add_to_last(sc);
            }
    if (fout.rdbuf() == cout.rdbuf()) 
        a.Print_list(fout);
    else a.Print_list_one_line_(fout);
}

/*

//Get score of student - Gia Bao
void Student_management_service::Export_scores_of_student(const string username,ostream &fout)
{
    ifstream f;
    f.open("score.txt");
    string s;
    int i,j;
    Score_list _list;
    Score tmp;
    while (getline(f,s))
    {
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
    // Print
    fout << "Score of student " << username << endl;
    _list.Print_list(fout);
}

//Get score of course - Gia Bao
void Student_management_service::Export_scores_of_course(const string course_id,ostream &fout)
{
    ifstream f;
    f.open("score.txt");
    string s;
    int i,j;
    Score_list _list;
    Score tmp;
    while (getline(f,s))
    {
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
    // Print
    fout << "Score of course: " << course_id << endl;
    _list.Print_list(fout);
}

*/

// View checkin in a course - Van Nam
void Student_management_service::View_checkin_of_course(string stuID)
{
    string course_code, year; int semester;
    cout << "Enter course code\n";
    cin >> course_code;
    cout << "Enter year\n";
    cin >> year;
    cout << "Enter semester\n";
    cin >> semester;
    CSV_helper check;
    Course res;
    if (!check.Get_details("course.txt", course_code, year, semester, res))
    {
        cout << "Course doesn't exist" << endl;
        return ;
    }
    if (check.Is_student_in_course(stuID,course_code,year,semester)==0)
    {
        cout<<"This student does not attend to this course!\n";
        return;
    }
    ifstream f;
    string S, s, c, y, ID;
    long long a = 0;
    int week;
    f.open("presence.txt");
    while (getline(f,S))
    {
        /// Code
        Next_token(S,s);
        if (s != course_code) continue;
        /// Year
        Next_token(S,s);
        if (s != year) continue;
        /// Semester
        Next_token(S,s);
        if (to_int(s) != semester) continue;
        /// StuID
        Next_token(S,ID);
        /// Week
        week = to_int(S); 
        /// Bit
        a |= (1<<(week-1));
    }
    int num_week = res.Count_week();
    for (int i=0;i<num_week;++i)
        if ((a>>i)&1)
            cout << "Week " << i+1 << ": present\n";
        else cout << "Week " << i+1 << ": absent\n";
    f.close();
}

//Get list of student who was present - Van Nam
void Student_management_service::Print_present (string course_code,ostream &fout)
{
    fout << "   List of student who was present in class " << course_code << endl;
    Student_list list;
    CSV_helper helper;
    
    string line, tmp, week= "1", tmp_week, student_id, tmp_course;
    string number_of_week = "10";
    User guy;
    int swi= 0;
    
    ifstream presence;
    presence.open ("presence.txt");
    
    fout << "Week 1: " << endl << "Attending students: " << endl;
    while (!presence.eof())
    {
        if (swi== 0)
            // swi== 0 means Next_token took in the last data of the line (week data)
            // So we read the next line
            presence >> line;
        swi= Next_token (line, tmp_course);
        if (tmp_course.compare (course_code)== 0)
        {
            swi= Next_token (line, tmp);
            swi= Next_token (line, tmp);
            swi= Next_token (line, student_id);
            swi= Next_token (line, tmp_week);
            if (week== tmp_week)
            {
                // Add the student to the present list and remove them from the asbent list
                if (helper.Get_details("user.txt",student_id,guy))
                {
                    list.Add_to_last (guy);
                }
            }
            else
            {
                // Moving to the next week:
                // Print out the lists of present and absent students
                list.Print_list (fout);
                // Reset the lists
                list.Make_empty ();
                // Handle the empty weeks (if there are some)
                Plus_one_week (week);
                while (tmp_week!= week)
                {
                    fout << endl << "Week " << week << ": " << endl
                    << "No student attending the class." << endl;
                    Plus_one_week (week);
                }
                // Add the first student of the week to the present list
                // and remove them from the absent list
                if (helper.Get_details("user.txt",student_id,guy))
                {
                    list.Add_to_last (guy);
                }
                // Print out the title for the next week
                fout << endl << "Week " << tmp_week << ": " << endl
                << "Attending students: " << endl;
                week= tmp_week;
            }
        }
        else
        {
            swi= Next_token (line, tmp);
            swi= Next_token (line, tmp);
            swi= Next_token (line, tmp);
            swi= Next_token (line, tmp_week);
            if (tmp_week!= week)
            {
                // Moving to the next week
                // Print out the lists
                list.Print_list (fout);
                // And reset them
                list.Make_empty ();
                // Handle the empty weeks (if there are some)
                Plus_one_week (week);
                while (tmp_week!= week)
                {
                    fout << endl << "Week " << week << ": " << endl
                    << "No student attending the class." << endl;
                    Plus_one_week (week);
                }
                // Print out the title for the next week
                fout << endl << "Week " << tmp_week << ": " << endl
                << "Attending students: " << endl;
                week = tmp_week;
            }
        }
    }
    // The last week in the file presence.txt
    // Print out the lists
    list.Print_list (fout);
    // Remove the lists
    list.Make_empty ();
    // Handle the last empty weeks
    while (week!= number_of_week)
    {
        Plus_one_week (week);
        fout << endl << "Week " << week << ": " << endl
        << "No students attending the class." << endl;
    }
}

//Get list of student who was absent - Van Nam
void Student_management_service::Print_absent(string course_code,ostream &fout) {
    fout << "   List of student absent in class " << course_code << endl;
    Student_list absent;
    absent.List_all_student ();
    CSV_helper helper;
    
    string line, tmp, week= "1", tmp_week, student_id, tmp_course;
    string number_of_week = "10";
    User guy;
    int swi= 0;
    
    ifstream presence;
    presence.open ("presence.txt");
    
    fout << "Week 1: " << endl;
    while (!presence.eof())
    {
        if (swi== 0)
            // swi== 0 means Next_token took in the last data of the line (week data)
            // So we read the next line
            presence >> line;
        swi= Next_token (line, tmp_course);
        if (tmp_course.compare (course_code)== 0)
        {
            swi= Next_token (line, tmp);
            swi= Next_token (line, tmp);
            swi= Next_token (line, student_id);
            swi= Next_token (line, tmp_week);
            if (week== tmp_week)
            {
                // Add the student to the present list and remove them from the asbent list
                if (helper.Get_details("user.txt",student_id,guy))
                {
                    absent.Delete_node (student_id);
                }
            }
            else
            {
                // Moving to the next week:
                // Print out the lists of present and absent students
                fout << endl << "Absent students: " << endl;
                absent.Print_list (fout);
                // Reset the lists
                absent.Make_empty ();
                absent.List_all_student ();
                // Handle the empty weeks (if there are some)
                Plus_one_week (week);
                while (tmp_week!= week)
                {
                    fout << endl << "Week " << week << ": " << endl
                    << "No student attending the class." << endl
                    << "Absent students: " << endl;
                    absent.Print_list (fout);
                    Plus_one_week (week);
                }
                // Add the first student of the week to the present list
                // and remove them from the absent list
                if (helper.Get_details("user.txt",student_id,guy))
                {
                    absent.Delete_node (student_id);
                }
                // Print out the title for the next week
                fout << endl << "Week " << tmp_week << ": " << endl;
                week= tmp_week;
            }
        }
        else
        {
            swi= Next_token (line, tmp);
            swi= Next_token (line, tmp);
            swi= Next_token (line, tmp);
            swi= Next_token (line, tmp_week);
            if (tmp_week!= week)
            {
                // Moving to the next week
                // Print out the lists
                fout << endl << "Absent students: " << endl;
                absent.Print_list (fout);
                // And reset them
                absent.Make_empty ();
                absent.List_all_student ();
                // Handle the empty weeks (if there are some)
                Plus_one_week (week);
                while (tmp_week!= week)
                {
                    fout << endl << "Week " << week << ": " << endl
                    << "No student attending the class." << endl
                    << "Absent students: " << endl;
                    absent.Print_list (fout);
                    Plus_one_week (week);
                }
                // Print out the title for the next week
                week= tmp_week;
            }
        }
    }
    // The last week in the file presence.txt
    // Print out the lists
    fout << endl << "Absent students: " << endl;
    absent.Print_list (fout);
    // Handle the last empty weeks
    absent.Make_empty();
    absent.List_all_student ();
    while (week!= number_of_week)
    {
        Plus_one_week (week);
        fout << endl << "Week " << week << ": " << endl
        << "No students attending the class." << endl
        << "Absent students: " << endl;
        absent.Print_list (fout);
    }
}


//Check-in class
int Student_management_service::Is_ok_check_in(string username,string course_code,string year,int semester) {
    CSV_helper csv;
    Course c;
    string file_name = "course.txt";
    if (csv.Get_details(file_name,course_code,year,semester,c)) {
        Date d;
        Time t;
        string wday;
        Take_time(d,t,wday);
        if ((wday == c.date_of_week) && (Check_in_date(d,c)) && (Check_in_time(t,c))) {
            Course cou;
            cou.start_at = c.start_at;
            cou.end_at = d;
            return cou.Count_week();
        }
    }
    return 0;
}
