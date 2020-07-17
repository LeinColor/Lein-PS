#include <iostream>
using namespace std;
const int MAX_SIZE = 1001;
const int MOD = 10007;

int dp[MAX_SIZE][MAX_SIZE];
// nCk = (n-1)C(k-) + (n-1)C(k)
int comb(int N, int K)
{
	if (K == 0 || K == N) return 1;
	if (dp[N][K] != -1) return dp[N][K];
	
	dp[N][K] = comb(N - 1, K - 1) + comb(N - 1, K);

	return dp[N][K] % MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	fill(&dp[0][0], &dp[MAX_SIZE - 1][MAX_SIZE], -1);
	cout << comb(N, K);

	return 0;
}