#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int TABLE1[] = { 1,2,3,4,5 };
const int TABLE2[] = { 2,1,2,3,2,4,2,5 };
const int TABLE3[] = { 3,3,1,1,2,2,4,4,5,5 };
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p[3];
    fill(p, p + 3, 0);
    for (size_t i = 0; i < answers.size(); i++) {
        if (TABLE1[i % 5] == answers[i])
            p[0]++;
        if (TABLE2[i % 8] == answers[i])
            p[1]++;
        if (TABLE3[i % 10] == answers[i])
            p[2]++;
    }
    int max_value = max(max(p[0], p[1]), p[2]);
    for (int i = 0; i < 3; i++) {
        if (p[i] == max_value)
            answer.push_back(i + 1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> v{ 1,2,3,4,5 };
    vector<int> sol = solution(v);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }

    return 0;
}