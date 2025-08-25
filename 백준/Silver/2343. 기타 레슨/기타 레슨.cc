#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m, sum;

bool Check(vector<int>& v, int mid)
{
	for (int i = 0; i < n; i++) 
	{
		if (v[i] > mid) 
		{
			return false;
		}
	}

	int temp = mid;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (mid - v[i] < 0)
		{
			mid = temp;
			cnt++;
		}
		mid -= v[i];
	}

	if (mid != temp)
	{
		cnt++;
	}

	return cnt <= m;
}

int main(void)
{
	cin >> n >> m;
	
	vector<int> v(n, 0);
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	int left = 0;
	int right = sum;
	int result = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		if (Check(v, mid))
		{
			right = mid - 1;
			result = mid;
		}
		else
		{
			left = mid + 1;
		}
		
	}

	cout << result << '\n';

	return 0;
}