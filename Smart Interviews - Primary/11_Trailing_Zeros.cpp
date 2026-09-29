#include <bits/stdc++.h>
using namespace std;

bool is_leap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    string months[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                         "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    string weekdays[] = { "Thursday", "Friday", "Saturday", "Sunday",
                     "Monday", "Tuesday", "Wednesday"};
    for(int t = 1; t <= T; t++ ){
        long long n;
        cin >> n;
        long long days =  n / 86400;
        string weekday = weekdays[days % 7];
        int year = 1970;
        while(true) {
            int days_in_year = is_leap(year) ? 366 : 365;
            if(days < days_in_year)
                break;
                days -= days_in_year;
                year++;
        }
        int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(is_leap(year)) month_days[1] = 29;
        int month = 0;
        while(days >= month_days[month]){
            days -= month_days[month];
            month++;
        }
        int date = days + 1;
        if(date < 10)
            cout << "0";
        cout << date << "-" << months[month] << "-" << year << " " << weekday << "\n";
    }
    return 0;
}