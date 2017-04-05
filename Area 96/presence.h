// Nam

#include <iostream>
#include <string>
using namespace std;

class Presence
{
protected:
	string course_code;
	string student_id;
	int year;
	int semeter;
	int week;
public:
	void check_in (pair <string, string> primary_key, int week, int year, int semeter);
};
