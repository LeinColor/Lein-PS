#include <iostream>
using namespace std;
using ll = long long int;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		ll n, r;
		cin >> n >> r;
		if (n > r) cout << (r * (r + 1)) / 2 << '\n';
		else cout << ((n - 1) * n) / 2 + 1 << '\n';
	}
	return 0;
}