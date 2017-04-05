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

enum Week = {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

class Course
{
    string coure_code, year, course_name, lecturer_name;
    Date start_at, end_at;
    Time from, to;
    Week date_of_week;
    int semester;
} ;

#endif
