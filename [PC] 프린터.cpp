#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int> > dq;
    for (size_t i = 0; i < priorities.size(); i++)
        dq.push_back(make_pair(priorities[i], i));
    while (!dq.empty()) {
        bool flag = false;
        int priority = dq.front().first;
        int number = dq.front().second;
        for (auto&& document : dq) {
            if (priority < document.first) {
                dq.pop_front();
                dq.push_back(make_pair(priority, number));
                flag = true;
                break;
            }
        }

        if (!flag) {
            if (dq.front().second == location)
                return answer;
            dq.pop_front();
            answer++;
        }
    }
    return -1;
}