#include <iostream>
using namespace std;
using ll = long long int;

ll mul(ll A, ll B, ll C)
{
	if (B == 0) return 1;

	ll tmp = mul(A, B / 2, C);
	tmp = tmp * tmp % C;

	if (B % 2 == 0) return tmp;
	else return (tmp * A) % C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll A, B, C;
	cin >> A >> B >> C;

	cout << mul(A, B, C);

	return 0;
}