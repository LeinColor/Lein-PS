#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int prev_number = -1;
    int curr_number = -1;
    for (size_t i = 0; i < arr.size(); i++) {
        curr_number = arr[i];
        if (prev_number != curr_number) {
            answer.push_back(arr[i]);
        }
        prev_number = curr_number;
    }
    return answer;
}