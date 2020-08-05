#include <iostream>
using namespace std;
const int MAX_SIZE = 100001;

int N, M;
int duration[MAX_SIZE];
bool available(int mid)
{
	int sum = 0;
	int num = 1;

	for (int i = 0; i < N; i++) {
		if (duration[i] > mid)
			return false;

		sum += duration[i];
		if (sum > mid)
		{
			sum = duration[i];
			num++;
		}
	}
	return M >= num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int sum = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> duration[i];
		sum += duration[i];
	}

	int lo = 0, hi = sum, result = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (available(mid)) {
			result = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << result;
	return 0;
}