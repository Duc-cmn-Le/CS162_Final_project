#ifndef _SMS_H_
#define _SMS_H_
#include "user.h"
#include "course.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student_management_service
{
public:
    void Export_scores_of_student(const User u);
    void Export_scores_of_course(const Course c);
};
#endif
