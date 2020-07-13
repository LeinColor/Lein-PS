#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
const int MAX_SIZE = 200001;

priority_queue<int, vector<int>, greater<int> > pq_fastestEndTime;
struct Study {
	int S;
	int T;
};

bool cmp(const Study& a, const Study& b)
{
	if (a.S == b.S)
		return a.T < b.T;
	return a.S < b.S;
}

Study studies[MAX_SIZE];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> studies[i].S >> studies[i].T;
	}

	sort(studies, studies + N, cmp);

	pq_fastestEndTime.push(studies[0].T);

	for (int i = 1; i < N; i++) {
		if (pq_fastestEndTime.top() <= studies[i].S) {
			pq_fastestEndTime.pop();
			pq_fastestEndTime.push(studies[i].T);
		}
		else {
			pq_fastestEndTime.push(studies[i].T);
		}
	}

	cout << pq_fastestEndTime.size();

	return 0;
}