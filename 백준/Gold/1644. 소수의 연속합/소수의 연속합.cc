#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	vector<bool> temp(n + 1, true);

	for (int i = 2; i * i <= n; i++) {
		if (temp[i]) {
			for (int j = i * i; j <= n; j += i) {
				temp[j] = false;
			}
		}
	}

	vector<int> primes;

	for (int i = 2; i <= n; i++) {
		if (temp[i]) {
			primes.push_back(i);
		}
	}

	int size = (int)primes.size();
	int left = 0;
	int right = 0;
	int sum = 0;
	int result = 0;

	while (left < size) {

		while (right < size && sum < n) {
			sum += primes[right];
			right++;
		}

		if (sum == n) {
			result++;
		}

		sum -= primes[left];
		left++;
	}

	cout << result << '\n';

	return 0;
}