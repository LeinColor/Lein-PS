#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<string> result_vector;

    string split = "";
    for (auto& c : dartResult) {
        if (split.size() >= 2 && isdigit(c)) {
            result_vector.push_back(split);
            split = "";
        }
        split.push_back(c);
    }
    result_vector.push_back(split);

    vector<int> num_vector;
    for (int i = 0; i < result_vector.size(); i++) {
        int num = 0;
        string result = result_vector[i];
        if (isdigit(result[1])) num = (result[0] - '0') * 10 + result[1] - '0';
        else num = result[0] - '0';

        char power = 0;
        if (isdigit(result[1])) power = result[2];
        else power = result[1];
        switch (power) {
        case 'S':
            num = pow(num, 1);
            break;
        case 'D':
            num = pow(num, 2);
            break;
        case 'T':
            num = pow(num, 3);
            break;
        default:
            break;
        }

        switch (result[result.size() - 1]) {
        case '*':
            num *= 2;
            if (i != 0) num_vector[i - 1] *= 2;
            break;
        case '#':
            if (num > 0) num *= (-1);
            break;
        default:
            break;
        }
        num_vector.push_back(num);
    }
    for (auto& e : num_vector) answer += e;
    return answer;
}