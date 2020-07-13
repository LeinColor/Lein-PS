#include <iostream>
using namespace std;
const int INFINITE = 1234567890;
const int MAX_SIZE = 101;

int order[MAX_SIZE];
int next_use_pos[MAX_SIZE];
int slot[MAX_SIZE];
bool is_used[MAX_SIZE];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> order[i];
		slot[i] = -1;
	}

	int answer = 0;
	int current_index = 0;
	for (int i = 0; i < K; i++) {

		bool is_full = true;
		for (int j = 0; j < N; j++) {
			if (slot[j] == -1 && !is_used[order[i]]) {
				is_used[order[i]] = true;
				slot[j] = order[i];
				is_full = false;
				break;
			}
		}
		if (is_full && !is_used[order[i]]) {
			for (int j = 0; j < K; j++)
				next_use_pos[j] = INFINITE;

			for (int j = i; j < K; j++) {
				if (next_use_pos[order[j]] == INFINITE)
					next_use_pos[order[j]] = j;
			}

			int plug_off_value = -INFINITE;
			int plug_off_index = 0;
			for (int j = 0; j < N; j++) {
				if (next_use_pos[slot[j]] > plug_off_value) {
					plug_off_value = next_use_pos[slot[j]];
					plug_off_index = j;
				}
			}

			int plug_off_slot = slot[plug_off_index];
			is_used[plug_off_slot] = false;
			slot[plug_off_index] = order[i];
			is_used[order[i]] = true;
			answer++;
		}
	}

	cout << answer;
	return 0;
}