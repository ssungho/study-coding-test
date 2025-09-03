#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
pair<int, int> max_amount;
pair<int, int> target;
set<pair<int, int>> visited;

int BFS() {
	int result = -1;

	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {0, 0} });
	visited.insert({0, 0});

	while (!q.empty()) {
		int current_count = q.front().first;
		int current_a = q.front().second.first;
		int current_b = q.front().second.second;
		q.pop();

		if (current_a == target.first && current_b == target.second) {
			result = current_count;
			break;
		}

		int next_count = current_count + 1;

		// F
		
		if (visited.end() == visited.find({max_amount.first, current_b})) {
			q.push({next_count, {max_amount.first, current_b}});
			visited.insert({max_amount.first, current_b});
		}

		if (visited.end() == visited.find({current_a, max_amount.second})) {
			q.push({next_count , {current_a, max_amount.second}});
			visited.insert({current_a, max_amount.second});
		}

		// E

		if (visited.end() == visited.find({0, current_b})) {
			q.push({next_count, {0, current_b}});
			visited.insert({0, current_b});
		}

		if (visited.end() == visited.find({current_a, 0})) {
			q.push({next_count, {current_a, 0}});
			visited.insert({current_a, 0});
		}

		// M

		int sum = current_a + current_b;
		int move_ba = sum - max_amount.first;
		int move_ab = sum - max_amount.second;
		int na, nb;

		if (move_ba > 0) {
			na = max_amount.first;
			nb = move_ba;
		}
		else {
			na = sum;
			nb = 0;
		}

		if (visited.end() == visited.find({na, nb})) {
			q.push({next_count, {na, nb}});
			visited.insert({na, nb});
		}

		if (move_ab > 0) {
			na = move_ab;
			nb = max_amount.second;
		}
		else {
			na = 0;
			nb = sum;
		}

		if (visited.end() == visited.find({na, nb})) {
			q.push({next_count, {na, nb}});
			visited.insert({na, nb});
		}
	}

	return result;
}

int main(void) {
	cin >> max_amount.first >> max_amount.second >> target.first >> target.second;

	cout << BFS() << '\n';

	return 0;
}