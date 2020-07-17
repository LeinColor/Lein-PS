#include <iostream>
using namespace std;

int arr[41];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N, even = 0, odd = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			if ((i % 2) != (arr[i] % 2)) {
				if (i % 2 == 0) even++;
				else odd++;
			}
		}
		if (even == odd) cout << even << '\n';
		else cout << "-1\n";
	}
	return 0;
}