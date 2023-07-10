#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	vector<int> v;
	string temp;
	cin >> temp;
	for (int i = 0; i < temp.size(); i++)
	{
		char num = temp[i];
		v.push_back(num - '0');
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	return 0;
}