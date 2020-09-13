#include <string>
#include <vector>
using namespace std;

const char TABLE[] = { ' ', '#' };
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        int d = arr1[i] | arr2[i];
        string s = "";
        int k = 0;
        while (k++ < n) {
            s.push_back(TABLE[d & 1]);
            d = d >> 1;
        }
        string t = "";
        for (int j = s.size() - 1; j >= 0; j--)
            t.push_back(s[j]);
        answer.push_back(t);
    }
    return answer;
}