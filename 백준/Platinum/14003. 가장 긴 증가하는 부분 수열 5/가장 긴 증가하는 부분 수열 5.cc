#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> last_index;
vector<int> prev_index;
int n;

int BinarySearch(int value) {
	int result = (int)last_index.size();
	int left = 0;
	int right = result - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[last_index[mid]] >= value) {
			result = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	
	a.resize(n);
	prev_index.resize(n, -1);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		int index = BinarySearch(a[i]);

		if (last_index.empty() || a[last_index.back()] < a[i]) {
			last_index.push_back(i);
			index = last_index.size() - 1;
		} else {
			last_index[index] = i;
		}

		if (index > 0) {
			prev_index[i] = last_index[index - 1];
		}
	}

	vector<int> lis(last_index.size());
	int index = last_index.back();
	for (auto r_iter = lis.rbegin(); r_iter != lis.rend(); r_iter++) {
		*r_iter = a[index];
		index = prev_index[index];
	}

	cout << lis.size() << '\n';
	for (int i : lis) {
		cout << i << ' ';
	}

	return 0;
}