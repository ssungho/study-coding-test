#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> lis_last;
vector<int> last_prev;
int n;

int BinarySearch(int value)
{
	int result = (int)lis_last.size();
	int left_index = 0;
	int right_index = result - 1;

	while (left_index <= right_index)
	{
		int mid = (left_index + right_index) / 2;

		if (a[lis_last[mid]] >= value)
		{
			result = mid;
			right_index = mid - 1;
		}
		else
		{
			left_index = mid + 1;
		}
	}

	return result;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	a.resize(n + 1, 0);
	last_prev.resize(n + 1, -1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int index = 0;

		if (lis_last.empty() || a[lis_last.back()] < a[i])
		{
			lis_last.push_back(i);
			index = lis_last.size() - 1;
		}
		else
		{
			index = BinarySearch(a[i]);
			lis_last[index] = i;
		}

		if (index > 0)
		{
			last_prev[i] = lis_last[index - 1];
		}
	}

	int size = (int)lis_last.size();
	vector<int> lis(size);
	int index = lis_last.back();

	for (int i = size - 1; i >= 0; i--)
	{
		lis[i] = a[index];
		index = last_prev[index];
	}

	cout << size << '\n';

	for (auto i : lis)
	{
		cout << i << ' ';
	}

	return 0;
}