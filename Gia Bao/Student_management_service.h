#ifndef _SMS_H_
#define _SMS_H_
#include "user.h"
#include "course.h"
#include "score.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student_management_service
{
public:
    void Export_scores_of_student(const string username);
    void Export_scores_of_course(const string course_id);
};
int to_int(const string);
double to_double(const string);
#endif
