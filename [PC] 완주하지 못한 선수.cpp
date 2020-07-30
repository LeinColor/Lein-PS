#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map_part, map_comp;
    for (auto& part : participant) map_part[part]++;
    for (auto& comp : completion) map_comp[comp]++;
    for (auto& element : map_part) {
        string key = element.first;
        int value = element.second;
        if (map_comp[key] != value) {
            answer = key;
            break;
        }
    }
    return answer;
}