#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	double n;
	cin >> n;

	if ((int)n == 0)
	{
		cout << 0;
		return 0;
	}

	vector<double> v;
	for (int i = 0; i < n; i++)
	{
		double op;
		cin >> op;
		v.push_back(op);
	}

	sort(v.begin(), v.end());

	double cut = round(n * 0.15);
	double sum = 0;
	for (int i = cut; i < n - cut; i++)
		sum += v[i];

	double average = round(sum / (n - 2 * cut));
	cout << average;

	return 0;
}