#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    for (auto& c : s) {
        if (isdigit(c)) {
            answer *= 10;
            answer += c - '0';
        }
    }
    return (s[0] == '-') ? -answer : answer;
}