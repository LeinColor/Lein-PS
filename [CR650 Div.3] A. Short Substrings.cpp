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
		string s;
		cin >> s;
		cout << s[0];
		for (int i = 1; i < s.length(); i++) {
			if (i % 2 == 1) {
				cout << s[i];
			}
		}
		cout << '\n';
	}


	return 0;
}