#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class date{
    public:
        int year;
        int month;
        int day;
        date()
        {
            year = 0;
            month = 0;
            day = 0;
        }
};
int get_fine(date r_date, date d_date)
{
    int fine = 0;
    if (d_date.year < r_date.year)
    {
        fine = 10000;
    }
    else if (d_date.year == r_date.year)
    {
        //in same year
        if(d_date.month <  r_date.month)
        {
            fine = 500 * (r_date.month - d_date.month);
        }
        else if(d_date.month ==  r_date.month){
            if(d_date.day <  r_date.day)
            {
                fine = 15 * (r_date.day - d_date.day);
            }
        }
    }
    return fine;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int y,m,d;
    date r_date;
    date d_date;
    cin >> r_date.day >> r_date.month >> r_date.year;
    cin >> d_date.day >> d_date.month >> d_date.year;
    //cout << "return:" << r_date.day << " " << r_date.month << " "<< r_date.year <<endl;
    //cout << "due   :" << d_date.day << " " << d_date.month << " "<< d_date.year <<endl;
    cout <<  get_fine(r_date, d_date);
    return 0;
}
