#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	const string s[] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
	const int v[] = { 0,1,2,3,4,5,6,7,8,9 };

	long long int answer = 0;
	for (int i = 0; i < 2; i++) {
		string r;
		cin >> r;
		for (int j = 0; j < 10; j++) {
			if (r == s[j]) {
				answer += v[j] * (long long int)pow(10, 1 - i);
				break;
			}
		}
	}
	string w;
	cin >> w;
	for (int i = 0; i < 10; i++) {
		if (w == s[i]) {
			answer *= (long long int)pow(10, i);
			break;
		}
	}

	cout << answer;

	return 0;
}