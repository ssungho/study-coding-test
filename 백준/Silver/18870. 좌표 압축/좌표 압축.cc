#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<long> v1;
	for (int i = 0; i < N; i++) // O(n)
	{
		long temp;
		cin >> temp;
		v1.push_back(temp);
	}

	vector<long> v2 = v1;
	sort(v2.begin(), v2.end()); // nlog(n)
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	
	for (int i = 0; i < N; i++)
	{
		int temp = v1[i];
		int idx = lower_bound(v2.begin(), v2.end(), temp) - v2.begin(); // O(n)보다 빠름(이진탐색기반) 
		cout << idx << " ";
	}

	return 0;
}