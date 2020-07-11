#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 0;
	while (++N) {
		int L, P, V;
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0)
			return 0;

		int quotient = (P < V) ? (V / P) * L : L;
		int remainder = (P < V) ? (V % P) : 0;
		if (remainder > L) remainder = L;
		cout << "Case " << N << ": " << quotient + remainder << '\n';
	}
	return 0;
}