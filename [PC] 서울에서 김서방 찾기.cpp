#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul)
{
    string s = "";
    for (size_t i = 0; i < seoul.size(); i++)
        if (seoul[i] == "Kim")
            s += "김서방은 " + to_string(i) + "에 있다";
    return s;
}