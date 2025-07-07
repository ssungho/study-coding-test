#include <iostream>
#include <algorithm>

using namespace std;

int numbers[15001]{};

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers, numbers + N);

    int left = 0;
    int right = N - 1;
    int count = 0;

    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum > M)
        {
            right--;
        }
        else if (sum < M)
        {
            left++;
        }
        else
        {
            count++;
            left++;
            right--;
        }
    }

    cout << count << '\n';

    return 0;
}