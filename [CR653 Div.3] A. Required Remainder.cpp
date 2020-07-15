#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int answer = 0;
		int x, y, n;
		cin >> x >> y >> n;

		int k = n - y;
		cout << k - (k % x) + y << '\n';
	}

	return 0;
}