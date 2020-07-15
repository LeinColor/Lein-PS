#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 51;

int answer;
void update_eatable_max(const string (&s)[MAX_SIZE], int N)
{
	int count = 0;

	// check row direction
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 1; j < N; j++) {
			if (s[i][j - 1] == s[i][j]) {
				count++;
			}
			else {
				answer = max(answer, count);
				count = 1;
			}
		}
		answer = max(answer, count);
	}

	// check column direction
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 1; j < N; j++) {
			if (s[j - 1][i] == s[j][i]) {
				count++;
			}
			else {
				answer = max(answer, count);
				count = 1;
			}
		}
		answer = max(answer, count);
	}
}

void clone_string(string (&target)[MAX_SIZE], const string (&source)[MAX_SIZE], int N)
{
	for (int i = 0; i < N; i++)
		target[i] = source[i];
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string s[MAX_SIZE];
	string clone[MAX_SIZE];
	for (int i = 0; i < N; i++)
		cin >> s[i];

	clone_string(clone, s, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j < N - 1) {
				swap(clone[i][j], clone[i][j + 1]);
				update_eatable_max(clone, N);
				swap(clone[i][j], clone[i][j + 1]);
			}

			if (i < N - 1) {
				swap(clone[i][j], clone[i + 1][j]);
				update_eatable_max(clone, N);
				swap(clone[i][j], clone[i + 1][j]);
			}

		}
	}

	cout << answer;

	return 0;
}