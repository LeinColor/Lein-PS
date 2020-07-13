#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1001;

struct Homework {
	int d, w;
};

bool cmp(const Homework& a, const Homework& b)
{
	if (a.w == b.w)
		return a.d > b.d;
	return a.w > b.w;
}

Homework homeworks[MAX_SIZE];
int day[MAX_SIZE];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> homeworks[i].d >> homeworks[i].w;

	sort(homeworks + 1, homeworks + N + 1, cmp);

	for (int i = 1; i <= N; i++) {
		int deadline = homeworks[i].d;
		while (deadline >= 1) {
			if (day[deadline] == 0) {
				day[deadline] = i;
				break;
			}
			else {
				deadline--;
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= MAX_SIZE; i++) {
		if (day[i] != 0) {
			answer += homeworks[day[i]].w;
		}
	}

	cout << answer;

	return 0;
}