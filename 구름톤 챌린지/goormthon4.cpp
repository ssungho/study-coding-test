#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // 강도가 가장 높은 재료 기준으로 위/아래로 갈수록 맛의 강도가 낮아져야 함.
    // 완벽하지 않다면 0 출력

    int N, max = -1;
    int sum = 0;
    vector<int> arr;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        if (temp > max)
            max = temp;

        arr.push_back(temp);
    }

    bool find = false;
    if (arr[0] == max)
        find = true;

    for (int i = 0; i < N - 1; i++)
    {
        if (!find)
        {
            if (arr[i] < arr[i - 1])
            {
                cout << '0';
                return 0;
            }
        }
        else
        {
            if (arr[i + 1] > arr[i])
            {
                cout << '0';
                return 0;
            }
        }
        if (arr[i] == max)
            find = true;

        sum += arr[i];
    }
    cout << sum + arr[N - 1];
    return 0;
}