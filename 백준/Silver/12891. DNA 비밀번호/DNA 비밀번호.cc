#include<iostream>
#include<vector>
#include<string>
using namespace std;
// boj 12891번

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s_length, p_length;
	string dna;
	int need[4]{0,0,0,0};
	int check[4]{0,0,0,0};

	cin >> s_length >> p_length;
	cin >> dna;
	for (int i = 0; i < 4; i++)
	{
		int temp;
		cin >> temp;
		need[i] = temp;
	}
	int cnt = 0;
	// need배열 초기화
	for (int i = 0; i < p_length; i++)
	{
		if (dna[i] == 'A')
			check[0]++;
		else if (dna[i] == 'C')
			check[1]++;
		else if (dna[i] == 'G')
			check[2]++;
		else
			check[3]++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (need[i] > check[i])
			break;
		if (i == 3 && need[i] <= check[i])
			cnt++;
	}
	// 맞는지 확인
	for (int i = 0; i < s_length - p_length; i++)
	{
		char head = dna[i];
		char tail = dna[i + p_length];

		if (head == 'A')
			check[0]--;
		else if (head == 'C')
			check[1]--;
		else if (head == 'G')
			check[2]--;
		else
			check[3]--;

		if (tail == 'A')
			check[0]++;
		else if (tail == 'C')
			check[1]++;
		else if (tail == 'G')
			check[2]++;
		else
			check[3]++;

		for (int i = 0; i < 4; i++)
		{
			if (need[i] > check[i])
				break;
			if (i == 3 && need[i] <= check[i])
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}