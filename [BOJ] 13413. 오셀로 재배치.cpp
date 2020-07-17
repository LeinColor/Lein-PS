#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		
		int count_W = 0, count_B = 0, diff = 0;
		string source, target;
		cin >> source >> target;
		for (int i = 0; i < N; i++) {
			if (source[i] != target[i]) {
				diff++;

				if (source[i] == 'W') {
					count_W++;
				}
				else if (source[i] == 'B') {
					count_B++;
				}
			}
		}
		cout << diff - min(count_W, count_B) << '\n';
	}

	return 0;
}