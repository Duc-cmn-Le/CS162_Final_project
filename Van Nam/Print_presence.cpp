// Nam
// Print out the list of student attending or not attending classes

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

#include "Student_management_service.h"
#include "user.h"
#include "CSVhelper.h"

int __Next_token (string &s, string &target) 
{
    target = "";
    int cnt = 0;
    for (string::iterator i=s.begin();i!=s.end();++i,cnt++)
        if (*i == ',') {
            target.insert(target.begin(),s.begin(),i);
            s.erase(0,cnt+1);
            return true;
        }
    target = s;
    return false;
}

void Plus_one_week (string &week)
{
        if (week == "9") week = "10";
        else if (week == "19") week = "20";
        else if (week.length() == 1) week[0]++;
        else week[1]++;
}

void Students_management_service::Print_presence (string course_code,ostream &fout)
{
	Student_list list, absent;
	absent.List_all_student ();
	CSV_helper helper;

	string line, tmp, week= "1", tmp_week, student_id, tmp_course;
        User guy;
	int swi= 0;

	ifstream presence;
	presence.open ("presence.txt");

	cout << "Week 1: " << endl << "Attending students: " << endl;
	while (!presence.eof())
	{
		if (swi== 0) 
			// swi== 0 means __Next_token took in the last data of the line (week data)
			// So we read the next line
			presence >> line;
		swi= __Next_token (line, tmp_course);
		if (tmp_course.compare (course_code)== 0)
		{
			swi= __Next_token (line, student_id);
			swi= __Next_token (line, tmp);
			swi= __Next_token (line, tmp);
			swi= __Next_token (line, tmp_week);
			if (week== tmp_week)
			{
				// Add the student to the present list and remove them from the asbent list
                                if (helper.Get_details("user.txt",student_id,guy)) 
                                {
                                    list.Add_to_last (guy);
                                    absent.Delete_node (student_id);
                                }
			}
			else
			{
				// Moving to the next week:
				// Print out the lists of present and absent students
				list.Print_list (fout);
				cout << endl << "Absent students: " << endl;
				absent.Print_list (fout);
				// Reset the lists
				list.Make_empty ();
				absent.Make_empty ();
				absent.List_all_student ();
				// Add the first student of the week to the present list
				// and remove them from the absent list
                                if (helper.Get_details("user.txt",student_id,guy)) 
                                {
                                    list.Add_to_last (guy);
                                    absent.Delete_node (student_id);
                                }
				// Handle the empty weeks (if there are some)
				Plus_one_week (week);
				while (tmp_week!= week)
				{
					cout << endl << "Week " << week << ": " << endl
						<< "No student attending the class." << endl
						<< "Absent students: " << endl;
					absent.Print_list (fout);
					Plus_one_week (week);
				}
				// Print out the title for the next week
				cout << endl << "Week " << tmp_week << ": " << endl
					<< "Attending students: " << endl;
				week= tmp_week;				
			}
		}
		else
		{
			swi= __Next_token (line, tmp);
			swi= __Next_token (line, tmp);
			swi= __Next_token (line, tmp);
			swi= __Next_token (line, tmp_week);
			if (tmp_week!= week)
			{
				// Moving to the next week
				// Print out the lists
				list.Print_list (fout);
				cout << endl << "Absent students: " << endl;
				absent.Print_list (fout);
				// And reset them
				list.Make_empty ();
				absent.Make_empty ();
				absent.List_all_student ();
				// Handle the empty weeks (if there are some)
				Plus_one_week (week);
				while (tmp_week!= week)
				{
					cout << endl << "Week " << week << ": " << endl
						<< "No student attending the class." << endl
						<< "Absent students: " << endl;
					absent.Print_list (fout);
					Plus_one_week (week);
				}
				// Print out the title for the next week
				cout << endl << "Week " << tmp_week << ": " << endl
					<< "Attending students: " << endl;
				week= tmp_week;
			}
		}
	}
	// The last week in the file presence.txt
	// Print out the lists
	list.Print_list (fout);
	cout << endl << "Absent students: " << endl;
	absent.Print_list (fout);
	// Remove the lists
	list.Make_empty ();
	absent.Make_empty ();
}

