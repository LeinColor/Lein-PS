#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    const string day[] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
    const int day_count[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int day_total = 0;
    string answer = "";
    for (int i = 0; i < a - 1; i++)
        day_total += day_count[i];
    day_total += b;
    answer = day[day_total % 7];
    return answer;
}