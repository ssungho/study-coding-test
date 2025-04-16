#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<int> LDS(N, 1);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (A[i] > A[j])
            {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    cout << *max_element(LDS.begin(), LDS.end());

    return 0;
}