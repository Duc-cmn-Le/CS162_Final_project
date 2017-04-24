#include "course.h"

bool LeapYear(int y)
{
    if (y% 400 == 0 || (y%100 != 0 && y%4 == 0))
        return true;
    return false;
}

int nth(int d, int m, int y)
{
    switch(m)
    {
        case 1: return d; break;
        case 2: return 31+d; break;
        case 3: return 59+LeapYear(y)+d; break;
        case 4: return 90+LeapYear(y)+d; break;
        case 5: return 120+LeapYear(y)+d; break;
        case 6: return 151+LeapYear(y)+d; break;
        case 7: return 181+LeapYear(y)+d; break;
        case 8: return 212+LeapYear(y)+d; break;
        case 9: return 243+LeapYear(y)+d; break;
        case 10: return 273+LeapYear(y)+d; break;
        case 11: return 304+LeapYear(y)+d; break;
        case 12: return 334+LeapYear(y)+d; break;
    }
    return 0;
}

int Course::Count_week()
{
    int cnt = 0;
    if (start_at.y == end_at.y)
        return (-nth(start_at.d,start_at.m,start_at.y) + nth(end_at.d,end_at.m,end_at.y)+7)/7;
    else {
        for (int i = start_at.y+1; i <= end_at.y-1; ++i)
            cnt += nth(31,12,i);
    }
    cnt = cnt + nth(31,12,start_at.y) - nth(start_at.d,start_at.m,start_at.y) + 7 + nth(end_at.d,end_at.m,end_at.y);
    return cnt/7;
}
