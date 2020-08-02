#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (size_t i = 0; i < commands.size(); i++) {
        vector<int> data;
        int start = commands[i][0] - 1;
        int end = commands[i][1];
        int pick = commands[i][2] - 1;
        data.assign(array.begin() + start, array.begin() + end);
        sort(data.begin(), data.end());
        answer.push_back(data[pick]);
    }
    return answer;
}