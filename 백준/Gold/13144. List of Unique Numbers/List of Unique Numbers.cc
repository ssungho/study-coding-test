#include <iostream>
#include <vector>

using namespace std;

constexpr int max_n{100001};
bool isin[max_n]{};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int left = 0;
	int right = 0;
	long result = 0;

	while (left < n && right < n) {
		if (isin[v[right]] == false) {
			isin[v[right]] = true;
			result += right - left + 1;
			right++;
		} else {
			isin[v[left]] = false;
			left++;
		}
	}

	cout << result << '\n';

	return 0;
}