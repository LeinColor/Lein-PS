#include <string>
#include <vector>
using namespace std;
const int MAX_SIZE = 30;

int students[MAX_SIZE];
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	fill(students, students + n, 1);
	for (size_t i = 0; i < lost.size(); i++)
		students[lost[i] - 1] = 0;
	for (size_t i = 0; i < reserve.size(); i++)
		students[reserve[i] - 1]++;
	for (int i = 0; i < n; i++) {
		if (students[i] == 2 && i > 0 && students[i - 1] == 0)
			students[i - 1] = students[i] = 1;
		if (students[i] == 2 && i < n && students[i + 1] == 0)
			students[i + 1] = students[i] = 1;
	}
	for (int i = 0; i < n; i++)
		if (students[i] >= 1) answer++;

	return answer;
}