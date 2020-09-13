#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX_V = 201;
const int INF = 1234567890;
using P = pair<int, int>;

// n 지점의 갯수
// s 시작점
// a A의 도착지점
// b B의 도착지점
// fares 그래프
vector<P> adj[MAX_V];
priority_queue<P, vector<P>, greater<P> > PQ;
int dist[MAX_V], path[MAX_V];
bool visited[MAX_V];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for (int i = 0; i < fares.size(); i++) {
        int u = fares[i][0];    // from
        int v = fares[i][1];    // to
        int w = fares[i][2];    // cost
        adj[u].push_back(P(v, w));
        adj[v].push_back(P(u, w));
    }

    // dijkstra
    fill(dist, dist + MAX_V, INF);
    fill(path, path + MAX_V, -1);
    fill(visited, visited + MAX_V, false);
    dist[s] = 0;
    PQ.push(P(0, s));

    while (!PQ.empty()) {
        int curr;
        do {
            curr = PQ.top().second;
            PQ.pop();
        } while (!PQ.empty() && visited[curr]);

        if (visited[curr]) break;

        visited[curr] = true;
        for (auto& p : adj[curr]) {
            int next = p.first, d = p.second;
            if (dist[next] > dist[curr] + d) {
                dist[next] = dist[curr] + d;
                path[next] = curr;
                PQ.push(P(dist[next], next));
            }
        }
    }

    vector<int> a_path, b_path;
    int trace = a;
    while (trace != s) {
        trace = path[trace];
        a_path.push_back(trace);
    }
    trace = b;
    while (trace != s) {
        trace = path[trace];
        b_path.push_back(trace);
    }
    for (auto& e : a_path)
        cout << e << " ";
    cout << '\n';
    for (auto& e : b_path)
        cout << e << " ";

    answer = dist[a];

    return answer;
}

int main()
{
    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;

    int fares[][3] = { {4,1,10},{3,5,24},{5,6,2},{3,1,41},{5,1,24},{4,6,50},{2,4,66},{2,3,22},{1,6,25} };

    vector<vector<int>> f;
    for (int i = 0; i < 9; i++) {
        vector<int> q;
        for (int j = 0; j < 3; j++) {
            q.push_back(fares[i][j]);
        }
        f.push_back(q);
    }

    solution(n, s, a, b, f);

    return 0;
}