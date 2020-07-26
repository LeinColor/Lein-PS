#include <iostream>
#include <string>
using namespace std;

int max_answer, min_answer;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 2; i++) {
		int n;
		cin >> n;

		for (int j = 1; n > 0; j *= 10, n /= 10) {
			if (n % 10 == 5 || n % 10 == 6) {
				max_answer += 6 * j;
				min_answer += 5 * j;
			}
			else {
				max_answer += (n % 10) * j;
				min_answer += (n % 10) * j;
			}
		}
	}
	cout << min_answer << " " << max_answer;

	return 0;
}