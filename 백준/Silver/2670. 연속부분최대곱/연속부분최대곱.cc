#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr int MAX_N{10000};
double arr[MAX_N]{};
double dp[MAX_N]{};

int main(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 1; i < N; i++)
    {
        dp[i] = max(dp[i], dp[i] * dp[i - 1]);
    }

    double max_ele = *max_element(dp, dp + N);
    cout.precision(3);
    cout << fixed << round(max_ele * 1000.0) / 1000.0;

    return 0;
}