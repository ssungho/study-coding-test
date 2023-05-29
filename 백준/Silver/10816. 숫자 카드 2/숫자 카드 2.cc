#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, m;

	cin >> n;
	
	vector<int> v1;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v1.push_back(temp);
	}
	
	// 이진탐색관련 함수를 사용하기 위해 정렬..
	std::sort(v1.begin(), v1.end());

	cin >> m;

	vector<int> v2;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		v2.push_back(temp);
	}

	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		cnt = upper_bound(v1.begin(), v1.end(), v2[i]) - lower_bound(v1.begin(), v1.end(), v2[i]);
		cout << cnt << " ";
	}

	return 0;
}