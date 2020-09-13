#include <iostream>
#include <bitset>

#include <string>
#include <vector>
using namespace std;

const string LANGUAGE[] = { "cpp", "java", "undefined", "python" };
const string JOB_GROUP[] = { "backend", "frontend" };
const string CAREER[] = { "junior", "senior" };
const string SOUL_FOOD[] = { "chicken", "pizza" };
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> info_vector;
    vector<int> info_score;

    for (int i = 0; i < info.size(); i++) {
        vector<string> info_split;
        size_t prev = 0, curr;
        curr = info[i].find(' ');

        int bit = 0;
        int info_split_count = 0;
        // 0 ... n-1 string
        while (curr != string::npos)
        {
            string substring = info[i].substr(prev, curr - prev);
            prev = curr + 1;
            curr = info[i].find(' ', prev);

            //info_split.push_back(substring);
            switch (info_split_count) {
            case 0:
                // get language (info_split[0])
                for (int j = 0; j < 4; j++) {
                    if (LANGUAGE[j] == substring) {
                        bit |= (j + 1);
                        break;
                    }
                }
                break;
            case 1:

                // get job group (info_split[1])
                for (int j = 0; j < 2; j++) {
                    if (JOB_GROUP[j] == substring) {
                        bit |= (j + 1) << 3;
                        break;
                    }
                }
                break;
            case 2:
                // get career (info_split[2])
                for (int j = 0; j < 2; j++) {
                    if (CAREER[j] == substring) {
                        bit |= (j + 1) << 5;
                        break;
                    }
                }
                break;
            case 3:
                // get soul food (info_split[3])
                for (int j = 0; j < 2; j++) {
                    if (SOUL_FOOD[j] == substring) {
                        bit |= (j + 1) << 7;
                        break;
                    }
                }
                break;
            default:
                break;
            }
            info_split_count++;
        }

        // nth string
        string substring = info[i].substr(prev, curr - prev);
        info_score.push_back(stoi(substring));
        info_vector.push_back(bit);
    }


    // query
    for (int i = 0; i < query.size(); i++) {
        vector<string> query_split;
        size_t prev = 0, curr;
        curr = query[i].find(' ');

        int bit = 0;
        int query_split_count = 0;
        // 0 ... n-1 string
        while (curr != string::npos)
        {
            string substring = query[i].substr(prev, curr - prev);
            prev = curr + 1;
            curr = query[i].find(' ', prev);

            //query_split.push_back(substring);

            switch (query_split_count) {
            case 0:
                // get language (info_split[0])
                for (int j = 0; j < 4; j++) {
                    if (LANGUAGE[j] == substring) {
                        bit |= (j + 1);
                        break;
                    }
                }
                break;
            case 2:

                // get job group (info_split[1])
                for (int j = 0; j < 2; j++) {
                    if (JOB_GROUP[j] == substring) {
                        bit |= (j + 1) << 3;
                        break;
                    }
                }
                break;
            case 4:
                // get career (info_split[2])
                for (int j = 0; j < 2; j++) {
                    if (CAREER[j] == substring) {
                        bit |= (j + 1) << 5;
                        break;
                    }
                }
                break;
            case 6:
                // get soul food (info_split[3])
                for (int j = 0; j < 2; j++) {
                    if (SOUL_FOOD[j] == substring) {
                        bit |= (j + 1) << 7;
                        break;
                    }
                }
                break;
            default:
                break;
            }
            query_split_count++;
        }

        // nth string
        string substring = query[i].substr(prev, curr - prev);
        int score = stoi(substring);
        int cnt = 0;
        for (int k = 0; k < info_vector.size(); k++) {
            if ((bit == (bit & info_vector[k])) && score <= info_score[k]) {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}

int main()
{
    vector<string> info;
    vector<string> query;
    string a[] = { "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" };
    string b[] = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" };

    for (auto& e : a) info.push_back(e);
    for (auto& e : b) query.push_back(e);
    vector<int> ans = solution(info, query);
    for (auto& e : ans) cout << e << " ";

    return 0;
}