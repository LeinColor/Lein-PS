#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long int;
const int MAX_SIZE = 10001;

ll budgets[MAX_SIZE];
ll max_budget = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> budgets[i];
		max_budget = max(max_budget, budgets[i]);
	}

	int M;
	cin >> M;
	ll lo = 0, hi = max_budget;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			if (budgets[i] > mid) sum += mid;
			else sum += budgets[i];
		}
		if (sum <= M) lo = mid + 1;
		else hi = mid - 1;
	}
	cout << hi;
	return 0;
}