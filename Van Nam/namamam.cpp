
void Student_management_service::Print_present (string course_code,ostream &fout)
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
				// Add the first student of the week to the present list
				// and remove them from the absent list
                                if (helper.Get_details("user.txt",student_id,guy)) 
                                {
                                    list.Add_to_last (guy);
                                    absent.Delete_node (student_id);
                                }
				// Print out the title for the next week
				cout << endl << "Week " << tmp_week << ": " << endl
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
	// Handle the last empty weeks
	absent.List_all_student ();
	while (week!= last_week)
	{
		Plus_one_week (week);
		cout << endl << "Week " << week << ": " << endl
			<< "No students attending the class." << endl
			<< "Absent students: " << endl;
		absent.Print_list ();
	}
	absent.Make_empty ();
}
