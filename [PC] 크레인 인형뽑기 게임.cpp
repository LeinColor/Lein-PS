#include <string>
#include <vector>
using namespace std;

vector<int> picked;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    for (auto& move : moves) {
        int pick = move - 1;
        for (size_t i = 0; i < board.size(); i++) {
            if (board[i][pick] != 0) {
                picked.push_back(board[i][pick]);
                board[i][pick] = 0;
                break;
            }
        }

        int top = picked[picked.size() - 1];
        if (picked.size() >= 2) {
            int second_top = picked[picked.size() - 2];
            if (top == second_top) {
                answer += 2;
                picked.pop_back();
                picked.pop_back();
            }
        }
    }
    return answer;
}