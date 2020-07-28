#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX_SIZE = 101;

struct Table {
	int number;
	int time;
};

bool cmp(const Table& a, const Table& b)
{
	if (a.time == b.time)
		return a.number < b.number;
	return a.time < b.time;
}

void shift(Table(&table)[MAX_SIZE], int start, int end)
{
	int index = start;

	while (index < end - 1) {
		table[index].number = table[index + 1].number;
		table[index].time = table[index + 1].time;
		index++;
	}
}

void print(Table (&table)[MAX_SIZE], int end)
{
	if (end == 0) {
		cout << "sleep\n";
		return;
	}

	for (int i = 0; i < end; i++) {
		cout << table[i].number << " ";
	}
	cout << '\n';
}

int find(Table (&table)[MAX_SIZE], int target)
{
	for (int i = 0; i < MAX_SIZE; i++) {
		if (table[i].number == target)
			return i;
	}
	return -1;
}

Table tables[MAX_SIZE];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int count = 0;

	while (N--) {
		string query;
		cin >> query;

		if (query == "order") {
			int order_num, order_time;
			cin >> order_num >> order_time;
			tables[count].number = order_num;
			tables[count].time = order_time;
			++count;
		}
		else if (query == "sort") {
			sort(tables, tables + count, cmp);
		}
		else if (query == "complete") {
			int complete_num;
			cin >> complete_num;

			int target_index = find(tables, complete_num);
			shift(tables, target_index, count);
			--count;
		}
		print(tables, count);
	}

	return 0;
}