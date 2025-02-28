#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    // 5일이 최대. 15 + 5 = 20
    int T[20]{};
    int P[20]{};
    int memo[20]{};

    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i > 0; i--)
     {
        if (T[i] + i -1 <= N) 
            memo[i] = max(P[i] + memo[i + T[i]], memo[i + 1]);
        else
            memo[i] = memo[i + 1];
    }

    cout << memo[1];
    
    return 0;
}