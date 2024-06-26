#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    string date;
    if (year == 1918) {
        // In 1918, the date of the 256th day of the year was September 26th, due to a calendar change.
        date = "26.09.1918";
    } else if (year < 1918) {
        // In the Julian calendar, leap years are divisible by 4.
        if (year % 4 == 0) {
            date = "12.09." + to_string(year);
        } else {
            date = "13.09." + to_string(year);
        }
    } else {
        // In the Gregorian calendar, leap years are either divisible by 400 or divisible by 4 but not divisible by 100.
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            date = "12.09." + to_string(year);
        } else {
            date = "13.09." + to_string(year);
        }
    }
    return date;
}

int main()
{
    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
