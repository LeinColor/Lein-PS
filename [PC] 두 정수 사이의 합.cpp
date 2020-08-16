#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) swap(a, b);
    while (a <= b) answer += a++;
    return answer;
}
