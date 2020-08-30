#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1000001;

bool is_prime[MAX_SIZE];
int solution(int n) {
    int answer = 0;
    fill(is_prime, is_prime + n, true);
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) answer++;
        for (int j = i * 2; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return answer;
}