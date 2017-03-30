// Nam

#include <iostream>
#include <string>
using namespace std;

class score
{
protected:
	string course_code;
	string student_id;
	int year;
	int semeter;
	int midterm;
	int lab;
	int final;
public:
	void scores_import (pair <string, string> primary_key, score S);
	score scores_export (pair <string, string> primary_key);
}