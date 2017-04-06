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

void Student_management_service::Print_presence (string course_code)
{
	Student_list list, absent;
	absent.List_all_student ();
	CSV_helper helper;

	string line, tmp, week= "1", tmp_week, student_id, tmp_course;
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
				list.Add_to_last (helper.Get_details (student_id));
				absent.Delete_node (student_id);
			}
			else
			{
				// Moving to the next week:
				// Print out the lists of present and absent students
				list.Print_list ();
				cout << endl << "Absent students: " << endl;
				asbent.Print_list ();
				// Reset the lists
				list.Remove_list ();
				absent.Remove_list ();
				absent.List_all_student ();
				// Add the first student of the week to the present list
				// and remove them from the absent list
				list.Add_to_last (helper.Get_details(student_id));
				absent.Delete_node (student_id);
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
				list.Print_list ();
				cout << endl << "Absent students: " << endl;
				absent.Print_list ();
				// And reset them
				list.Remove_list ();
				absent.Remove_list ();
				absent.List_all_student ();
				// Print out the title for the next week
				cout << endl << "Week " << tmp_week << ": " << endl
					<< "Attending students: " << endl;
				week= tmp_week;
			}
		}
	}
	// The last week in the file presence.txt
	// Print out the lists
	list.Print_list ();
	cout << endl << "Absent students: " << endl;
	absent.Print_list ();
	// Remove the lists
	list.Remove_list ();
	absent.Remove_list ();
}

