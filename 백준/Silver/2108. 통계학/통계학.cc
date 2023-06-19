#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	// 값들을 입력받을 벡터 v 선언
	vector<int> v;

	// num은 -4000 ~ 4000까지 최빈값을 구하기 위해 사용할 배열, 0으로 초기화
	// ex) num[0] = -4000의 값. 즉 num[i] = [i-4000] 
	int nums[8001]{0};

	// 최댓값과 최솟값을 선언 (범위를 구할때 사용)
	int max = -4000;
	int min = 4000;

	// 평균균과 중앙값을 구할 벡터 v와, 최빈값을 구할 배열 nums를 채워줌
	for (int i = 0; i < N; i++)
	{
		int temp = 0;

		cin >> temp;
		v.push_back(temp);

		if (max < temp)
			max = temp;

		if (min > temp)
			min = temp;

		nums[temp + 4000]++;
	}
	sort(v.begin(), v.end());

	// 평균 출력
	double avg = 0;

	for (int i = 0; i < N; i++)
		avg += v[i];

	avg /= N;
	cout << floor(avg + 0.5) << '\n';

	// 중앙값 출력
	int center = (N - 1) / 2;

	cout << v[center] << '\n';

	// 최빈값 출력
	int max_mode = 0;

	for (int i = 0; i < 8001; i++)
		if (nums[i] > max_mode)
			max_mode = nums[i];

	vector<int> mode_v;

	for (int i = 0; i < 8001; i++)
		if (nums[i] == max_mode)
			mode_v.push_back(i);

	sort(mode_v.begin(), mode_v.end());

	if(mode_v.size() > 1)
		cout << mode_v[1] - 4000 << '\n';
	else
		cout << mode_v[0] - 4000 << '\n';
	
	// 범위 출력
	cout << max - min;

	return 0;
}