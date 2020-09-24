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
    if (xv[0] == xv[1]) ans.push_back(xv[2]);
    else ans.push_back(xv[0]);
    if (yv[0] == yv[1]) ans.push_back(yv[2]);
    else ans.push_back(yv[0]);
    return ans;
}