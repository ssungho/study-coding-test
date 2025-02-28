#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<pair<int, int>> v(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> memo(N + 1, 0);
    int max_pay = 0;

    for (int i = N; i > 0; i--)
    {
        if (v[i].first + i - 1 <= N)
        {
            int next = i + v[i].first;
            int next_pay;

            if (next > N)
                next_pay = 0;
            else
                next_pay = memo[i + v[i].first];

            memo[i] = max(max_pay, next_pay + v[i].second);
        }
        else
        {
            memo[i] = max_pay;
        }
        
        max_pay = max(max_pay, memo[i]);
    }

    cout << max_pay;

    return 0;
}