#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int index = 0, answer = 0;
		while (index < n) {
			if (s[index] == '1') {
				index += k + 1;
				continue;
			}

			int start = index;
			int end = index + k + 1;

			int tmp = end - 1;
			bool available = true;
			if (tmp > n) tmp = n;
			while (tmp > start) {
				if (s[tmp] == '1') {
					index = tmp + k + 1;
					available = false;
					break;
				}

				tmp--;
			}
			if (available) {
				s[index] = '0';
				answer++;
				index = end;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}