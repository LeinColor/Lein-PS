#include <iostream>
using namespace std;
const int MAX_SIZE = 100001;

int arr[MAX_SIZE], cnt;
bool visited[MAX_SIZE];
bool finished[MAX_SIZE];
void dfs(int curr)
{
	visited[curr] = true;
	int next = arr[curr];

	if (visited[next]) {
		if (!finished[next]) {
			for (int i = next; i != curr; i = arr[i]) cnt++;
			cnt++;
		}
	}
	else dfs(next);
	finished[curr] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			arr[i]--;
		}

		fill(visited, visited + n, false);
		fill(finished, finished + n, false);
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) dfs(i);
		}
		cout << n - cnt << '\n';
	}

	return 0;
}