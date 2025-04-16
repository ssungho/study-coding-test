#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int A[1000]{};
    int Max_LIS[1000]{};
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        Max_LIS[i] = A[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                Max_LIS[i] = max(Max_LIS[i], Max_LIS[j] + A[i]);
            }
        }
    }

    cout << *max_element(Max_LIS, Max_LIS + N);

    return 0;
}