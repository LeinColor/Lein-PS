#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 11;

struct Solved {
	int D;
	int V;
};

bool cmp(const Solved& a, const Solved& b)
{
	return a.D < b.D;
}

Solved solved[MAX_SIZE];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < MAX_SIZE; i++)
		cin >> solved[i].D >> solved[i].V;

	sort(solved, solved + MAX_SIZE, cmp);

	int elapsed_minutes = 0;
	int answer = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		elapsed_minutes += solved[i].D;
		answer += elapsed_minutes + (20 * solved[i].V);
	}

	cout << answer;

	return 0;
}