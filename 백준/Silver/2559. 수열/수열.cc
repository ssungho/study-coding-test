#include <iostream>
#include <climits>

using namespace std;

int N, K;
int A[100001]{};
int S[100001]{};

int main(void)
{
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    
    for (int i = 1; i <= N; i++)
    {
        S[i] = S[i - 1] + A[i];
    }

    int maxSum = -INT_MAX;
    for (int i = 1; i <= N - K + 1; i++)
    {
        int partSum = S[i + K - 1] - S[i - 1];
        maxSum = max(partSum, maxSum);
    }

    cout << maxSum << '\n';

    return 0;
}