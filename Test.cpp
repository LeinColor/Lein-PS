#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    vector<int> xv, yv;
    for (auto& in : v) {
        xv.push_back(in[0]);
        yv.push_back(in[1]);
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    return ans;
}