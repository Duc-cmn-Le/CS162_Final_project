#ifndef _SMS_H_
#define _SMS_H_
#include "CSVhelper.h"
#include "user.h"
#include "course.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

class Student_management_service{
public:
    void Import_course(); // Finished
    void Import_student_list(); // Finished
    void Import_schedules();
    void Import_scores();
    
};
#endif
