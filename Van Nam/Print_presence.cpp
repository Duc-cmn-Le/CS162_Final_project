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
	if (week== "1") week= "2";
	else if (week== "2") week= "3";
	else if (week== "3") week= "4";
	else if (week== "4") week= "5";
	else if (week== "5") week= "6";
	else if (week== "6") week= "7";
	else if (week== "7") week= "8";
	else if (week== "8") week= "9";
	else if (week== "9") week= "10";
	else if (week== "10") week= "11";
	else if (week== "11") week= "12";
	else if (week== "12") week= "13";
	else if (week== "13") week= "14";
	else if (week== "14") week= "15";
	else if (week== "15") week= "16";
	else if (week== "16") week= "17";
	else if (week== "17") week= "18";
	else if (week== "18") week= "19";
	else if (week== "19") week= "20";
	else if (week== "20") week= "21";
}

void Students_management_service::Print_presence (string course_code)
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
				list.Add_to_last (helper.Get_details(student_id));
				absent.Delete_node (student_id);
			}
			else
			{
				// Moving to the next week:
				// Print out the lists of present and absent students
				list.Print_list ();
				cout << endl << "Absent students: " << endl;
				absent.Print_list ();
				// Reset the lists
				list.Remove_list ();
				absent.Remove_list ();
				absent.List_all_student ();
				// Add the first student of the week to the present list
				// and remove them from the absent list
				list.Add_to_last (helper.Get_details (student_id));
				absent.Delete_node (student_id);
				// Handle the empty weeks (if there are some)
				Plus_one_week (week);
				while (tmp_week!= week)
				{
					cout << endl << "Week " << week << ": " << endl
						<< "No student attending the class." << endl
						<< "Absent students: " << endl;
					absent.Print_list ();
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
				list.Print_list ();
				cout << endl << "Absent students: " << endl;
				absent.Print_list ();
				// And reset them
				list.Remove_list ();
				absent.Remove_list ();
				absent.List_all_student ();
				// Handle the empty weeks (if there are some)
				Plus_one_week (week);
				while (tmp_week!= week)
				{
					cout << endl << "Week " << week << ": " << endl
						<< "No student attending the class." << endl
						<< "Absent students: " << endl;
					absent.Print_list ();
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
	list.Print_list ();
	cout << endl << "Absent students: " << endl;
	absent.Print_list ();
	// Remove the lists
	list.Remove_list ();
	absent.Remove_list ();
}

