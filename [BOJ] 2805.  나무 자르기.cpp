#include <iostream>
using namespace std;
const int MAX_SIZE = 1000001;
using ll = long long int;

ll height[MAX_SIZE];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> height[i];

	ll lo = 0, hi = 1000000000;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			if (height[i] > mid)
				sum += height[i] - mid;
		}
		if (sum >= M) lo = mid;
		else hi = mid;
	}
	cout << lo;

	return 0;
}