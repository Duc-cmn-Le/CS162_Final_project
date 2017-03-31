#ifndef _COURSE_H_
#define _COURSE_H_

struct Date
{
    int d, m, y;
};

struct Time
{
    int s, m, h;
};

enum Week = {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

class Course
{
    string coureCode, Year, courseName, lecturerName;
    Date startAt, endAt;
    Time From, To;
    Week dateOfWeek;
    int Semester;
} ;

#endif
