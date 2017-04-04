// Nam
// Print out the list of student attending classes
// Print out absent students function is to-be-added.

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

#include "Student_management_service.h"
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
	Student_management_service list;
	CSV_helper helper;

	string line, tmp, week= "1", tmp_week, student_id, tmp_course;
	int swi= 0;

	ifstream presence;
	presence.open ("presence.txt");

	cout << "Week 1: " << endl << "Attending students: " << endl;
	while (!presence.eof())
	{
		if (swi== 0) 
			presence >> line;
		swi= __Next_token (line, tmp_course);
		if (tmp_course.compare (course_code)== 0)
		{
			swi= __Next_token (line, student_id);
			swi= __Next_token (line, tmp);
			swi= __Next_token (line, tmp);
			swi= __Next_token (line, tmp_week);
			if (week== tmp_week)
				list.Add_to_last (helper.Get_details(student_id));
			else
			{
				list.Print_list ();
				// Xoa cac sinh vien co mat (cac sinh vien trong list) --> cac sinh vien vang mat
				// Nhung chua co ham xoa
				list.Remove_list ();
				list.Add_to_last (helper.Get_details(student_id));	
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
				list.Print_list ();
				list.Remove_list ();
				cout << endl << "Week " << tmp_week << ": " << endl
					<< "Attending students: " << endl;
				week= tmp_week;
			}
		}
	}
	// Tuan cuoi cung
	list.Print_list ();
	// Xoa cac sinh vien co mat (cac sinh vien trong list) --> cac sinh vien vang mat
	// Nhung chua co ham xoa
	list.Remove_list ();
}

