// Nam
// Print out the list of student attending classes

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

#include "Student_management_service.h"
#include "CSVhelper.h"

void Student_management_service::Print_presence (char course_code[])
{
	CSV_helper helper;
	cout << "List of students who have come to " << course_code << " lessons: "
		<< endl;
	cout << "Week 1: " << endl;
	ifstream presence;
	presence.open ("presence.txt"); // Chua biet file presence.txt dat o dau.
	int week= 1;
	int tmp_week;
	bool print_last= false;
	char last [8];
	Student_management_service list;   // Linked list data structure

	while (!presence.eof())
	{
		if (print_last)
		{
			// Convert the first student_id of the week to Student and add them to the Linked List
			list.Add_to_last (helper.Convert_to_student (last));
			print_last= false;
		}
		char course [8];
		presence >> course;
		course [strlen(course)- 1] = '\0';
		if (strcmp(course, course_code)== 0) 
		{
			char student_id[10];
			presence >> student_id;
			student_id [strlen(student_id)- 1]= '\0'; 
			// Move file indicator
				{
				char tmp[20];
				presence >> tmp;
				presence >> tmp;
				}
			presence >> tmp_week;
			if (tmp_week== week)
				// Convert student_id to Student and add them to the Linked List.
				list.Add_to_last (helper.Convert_to_student (student_id));  
			else
			{
				// TEMP!!
				week= tmp_week;
				strcpy (last, student_id);
				print_last= true;
				cout << endl << "Week " << week << ": " << endl;
			}
		}
		else
		{
			char tmp[20];
			presence >> tmp;
			presence >> tmp;
			presence >> tmp;
			presence >> tmp_week;
			if (tmp_week!= week)
			{
				week++;
				list.Print_list ();
				cout << endl << "Week " << week << ": " << endl;
				Student_management_service list; // Create new list
			}
		}
	}
	list.Print_list ();
}

