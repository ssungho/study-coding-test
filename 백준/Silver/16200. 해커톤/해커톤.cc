#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> X(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }

    sort(X.begin(), X.end());

    int cntTeam = 0;

    for (int i = 0; i < N;)
    {
        int x = X[i];
        int cnt = 1;

        for (int j = i + 1; j < i + x; j++)
        {
            if (j >= N) 
            {
                break;
            }

            if (cnt < X[j])
            {
                cnt++;
            }
        }

        cntTeam++;
        i += cnt;
    }

    cout << cntTeam << '\n';

    return 0;
}