#include <iostream>

#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> m;
const string DELETE_EXCEPT_TABLE = "abcdefghijklmnopqrstuvwxyz0123456789-_.";
string solution(string new_id) {
    string answer = "";
    // step 1
    for (int i = 0; i < new_id.size(); i++) {
        if (isupper(new_id[i])) new_id[i] = new_id[i] - 'A' + 'a';
    }
    // step 2
    for (int i = 0; i < DELETE_EXCEPT_TABLE.size(); i++) {
        m[DELETE_EXCEPT_TABLE[i]] = 1;
    }

    for (int i = 0; i < new_id.size(); i++) {
        if (m.count(new_id[i]) == 0) {
            new_id.erase(i, 1);
            i--;
        }
    }
    // step 3
    char curr = 0;
    char prev = 0;
    for (int i = 0; i < new_id.size(); i++) {
        curr = new_id[i];
        if (curr == '.' && prev == '.') {
            new_id.erase(i, 1);
            i--;
        }
        prev = curr;
    }

    // step 4
    if (new_id.size() > 0) {
        if (new_id[0] == '.') new_id.erase(0, 1);
        if (new_id.size() > 0 && new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);
    }

    // step 5
    if (new_id.size() == 0) {
        new_id = "a";
    }

    // step 6
    if (new_id.size() >= 16) {
        for (int i = 15; i < new_id.size(); i++) {
            new_id.erase(i, 1);
            i--;
        }
    }

    if (new_id.size() > 0 && new_id[new_id.size() - 1] == '.') {
        new_id.erase(new_id.size() - 1);
    }

    // step 7
    while (new_id.size() <= 2) {
        new_id.push_back(new_id[new_id.size() - 1]);
    }

    answer = new_id;
    return answer;
}

int main()
{
    cout << solution("b.");
    return 0;
}