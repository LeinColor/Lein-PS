#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 501;

bool connection[MAX_SIZE][MAX_SIZE];
bool invite_target[MAX_SIZE];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		connection[a][b] = connection[b][a] = true;
	}
	
	int answer = 0;
	invite_target[1] = true;
	for (int i = 1; i <= n; i++) {
		if (connection[1][i]) {
			if (!invite_target[i]) {
				answer++;
				invite_target[i] = true;
			}
			for (int j = 1; j <= n; j++) {
				if (connection[i][j] && !invite_target[j]) {
					answer++;
					invite_target[j] = true;
				}
			}
		}
	}
	cout << answer;

	return 0;
}