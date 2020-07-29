#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 1000;

struct Edge {
	int to, cnt;
	Edge* dual;
	Edge() : Edge(-1, 0) {}
	Edge(int to1, int cnt1) : to(to1), cnt(cnt1), dual(nullptr) {}
};

int N, degree[MAX_SIZE];
vector<Edge*> adj[MAX_SIZE];
bool visited[MAX_SIZE];
int dfs(int curr)
{
	int result = 1;
	visited[curr] = true;
	for (Edge* e : adj[curr]) {
		int next = e->to;
		if (!visited[next]) result += dfs(next);
	}
	return result;
}

void Eulerian(int curr)
{
	for (Edge* e : adj[curr]) {
		if (e->cnt > 0) {
			e->cnt--;
			e->dual->cnt--;
			Eulerian(e->to);
		}
	}
	cout << curr + 1 << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int val;
			cin >> val;
			if (j > i && val > 0) {
				Edge* e1 = new Edge(j, val), * e2 = new Edge(i, val);
				e1->dual = e2;
				e2->dual = e1;
				adj[i].push_back(e1);
				adj[j].push_back(e2);
				degree[i] += val;
				degree[j] += val;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (degree[i] % 2 == 1) {
			cout << "-1\n";
			return 0;
		}
	}

	bool flag = false;
	int start = -1;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			int cSize = dfs(i);
			if (cSize > 1) {
				if (flag) {
					cout << "-1\n";
					return 0;
				}
				else {
					start = i;
					flag = true;
				}
			}
		}
	}

	if (start == -1) start = 0;

	Eulerian(start);
	return 0;
}