#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int factor_2 = 0, factor_3 = 0;
		while (n > 1 && n % 2 == 0) {
			n /= 2;
			factor_2++;
		}
		while (n > 1 && n % 3 == 0) {
			n /= 3;
			factor_3++;
		}

		if (n > 1) cout << "-1\n";
		else {
			if (factor_2 > factor_3) cout << "-1\n";
			else cout << (2 * factor_3) - factor_2 << '\n';
		}
	}

	return 0;
}