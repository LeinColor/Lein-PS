#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int answer;
unordered_map<string, int> map;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	while (N--) {
		string s;
		cin >> s;
		map.insert(make_pair(s, 1));
	}
	while (M--) {
		string s;
		cin >> s;
		if (map.count(s) == 1)
			answer++;
	}
	cout << answer;

	return 0;
}