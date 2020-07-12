#include <iostream>
using namespace std;
const int MAX_SIZE = 1001;

bool holes[MAX_SIZE];
int answer;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int pos;
		cin >> pos;
		holes[pos] = true;
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		if (holes[i]) {
			i += L - 1;
			answer++;
		}
	}

	cout << answer;

	return 0;
}