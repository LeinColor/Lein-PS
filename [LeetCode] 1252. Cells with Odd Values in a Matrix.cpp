class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int** matrix = new int*[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[m];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = 0;
            }
        }

        for (auto& indice_pair : indices) {
            int row = indice_pair[0];
            int col = indice_pair[1];

            for (int i = 0; i < m; i++)
                ++matrix[row][i];
            for (int i = 0; i < n; i++)
                ++matrix[i][col];
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] % 2 == 1)
                    ++answer;
            }
        }

        return answer;
    }
};