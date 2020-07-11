#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_LEN = 10 + 1;

int N;
int cost[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };
int answer = 1234567890;
int update_visited(int x, int y, bool flag)
{
	int total_cost = 0;

	for (int i = 0; i < 5; i++) {
		int next_dx = x + dx[i];
		int next_dy = y + dy[i];

		visited[next_dx][next_dy] = flag;
		
		total_cost += cost[next_dx][next_dy];
	}

	return total_cost;
}

void dfs(int depth, int x, int y, int total_cost)
{
	if (depth == 3) {
		answer = min(answer, total_cost);
		return;
	}

	// check if it is overlapped
	bool is_overlapped = false;

	for (int i = 0; i < 5; i++) {
		int next_dx = x + dx[i];
		int next_dy = y + dy[i];

		if (next_dx <= 0 || next_dx > N || next_dy <= 0 || next_dy > N || visited[next_dx][next_dy]) {
			is_overlapped = true;
			break;
		}
	}

	// if it is not overlapped, call next dfs
	if (!is_overlapped) {
		int additional_cost = update_visited(x, y, true);

		for (int i = 2; i <= N - 1; i++) {
			for (int j = 2; j <= N - 1; j++) {
				dfs(depth + 1, i, j, total_cost + additional_cost);
			}
		}

		// back to prev visited state
		update_visited(x, y, false);
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cost[i][j];
		}
	}
	
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 2; j <= N - 1; j++) {
			dfs(0, i, j, 0);
		}
	}

	cout << answer;
	return 0;
}