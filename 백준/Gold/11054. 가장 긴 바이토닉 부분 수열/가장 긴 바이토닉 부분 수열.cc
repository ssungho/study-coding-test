#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int A[1000]{};
    int LIS[1000]{};
    int LDS[1000]{};

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        LIS[i] = LDS[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (A[j] < A[i])
            {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        answer = max(answer, LIS[i] + LDS[i] - 1);
    }

    cout << answer;

    return 0;
}