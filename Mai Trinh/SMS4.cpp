
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

    }
}
