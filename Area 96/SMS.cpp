#include "SMS.h"

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
//Get score of course
//Get list of student who was present

//Get list of student who was absent

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
                // Add the first student of the week to the present list
                // and remove them from the absent list
                if (helper.Get_details("user.txt",student_id,guy)) 
                {
                    list.Add_to_last (guy);
                }
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
                // Add the first student of the week to the present list
                // and remove them from the absent list
                if (helper.Get_details("user.txt",student_id,guy)) 
                {
                    absent.Delete_node (student_id);
                }
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
