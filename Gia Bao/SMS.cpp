#include "SMS.h"

// Other function

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
// Import courses

//Import student list
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



//Import schedules

//Import scores
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

//Get score of student

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
//Get score of course

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

//Get list of student who was present
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

//Get list of student who was absent
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
