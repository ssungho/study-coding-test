#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int main(void)
{
	int T, N;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		vector<string> v;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			string temp;
			cin >> temp;

			v.push_back(temp);
		}

		if (N > 32)
		{
			cout << 0 << '\n';
			continue;
		}

		int cnt = 0;
		vector<int> dis;
		for (int i = 0; i < v.size() - 2; i++)
		{
			string temp1 = v[i];
			for (int j = i + 1; j < v.size() - 1; j++)
			{
				string temp2 = v[j];
				for (int k = j + 1; k < v.size(); k++)
				{
					string temp3 = v[k];
					for (int l = 0; l < 4; l++)
					{
						int dis1 = 0;
						int dis2 = 0;
						int dis3 = 0;

						for (int k = 0; k < 4; k++)
						{
							if (temp1[k] != temp2[k])
								dis1++;
							if (temp1[k] != temp3[k])
								dis2++;
							if (temp2[k] != temp3[k])
								dis3++;
						}
						dis.push_back(dis1 + dis2 + dis3);
					}
				}
			}
			sort(dis.begin(), dis.end());
			cnt = dis[0];
		}
		cout << cnt << '\n';
		
	}
	return 0;
}