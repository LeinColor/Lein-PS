#include <iostream>
#include <bitset>

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um[11];
string bitToString(int data)
{
    string s = "";
    char alphabet = 'A';
    while (data != 0) {
        if (data & 1) {
            s.push_back(alphabet);
        }
        data = data >> 1;
        alphabet++;
    }
    return s;
}
void backtrack(int data, int current, int depth, int end, const string& order)
{
    if (depth == end) {
        um[end][data]++;
        //cout << bitset<10>(data) << "\n";
        return;
    }

    for (int i = current; i < order.size(); i++) {
        data |= 1 << (order[i] - 'A');
        backtrack(data, i + 1, depth + 1, end, order);
        data &= ~(1 << (order[i] - 'A'));
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<int> data;
    for (int i = 0; i < orders.size(); i++) {
        int bit = 0;
        for (auto& c : orders[i]) {
            bit |= 1 << (c - 'A');
        }
        for (int j = 1; j <= orders[i].size(); j++) {
            backtrack(0, 0, 0, j, orders[i]);
        }
    }

    for (int i = 0; i < course.size(); i++) {
        int max_count = 0;
        for (auto& e : um[course[i]]) {
            max_count = max(max_count, e.second);
        }

        for (auto& e : um[course[i]]) {
            if (max_count <= 1) break;
            if (max_count == e.second)
                answer.push_back(bitToString(e.first));
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    string orders[] = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
    int course[] = { 2,3,5 };

    vector<string> vo;
    vector<int> vc;
    for (auto& e : orders) vo.push_back(e);
    for (auto& e : course) vc.push_back(e);
    vector<string> s = solution(vo, vc);
    for (auto& c : s) {
        cout << c << "\n";
    }

    return 0;
}