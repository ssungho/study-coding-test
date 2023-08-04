#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];  // 입력 받은 배열
int memo[100001]; // dp table

int main(void)
{

    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        int number;
        cin >> number;
        arr[i] = number;
    }
    int current_number;
    int max_sum = -2000;
    for (int i = 1; i < n + 1; i++)
    {
        current_number = arr[i];
        memo[i] = max(current_number, memo[i - 1] + current_number);
        max_sum = max(max_sum, memo[i]);
    }

    cout << max_sum;
}