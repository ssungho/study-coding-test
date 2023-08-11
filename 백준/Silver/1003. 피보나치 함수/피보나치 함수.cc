#include <iostream>
using namespace std;

int memo[41];
void fibonacci(int n)
{
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;

        fibonacci(num);
        if (num == 0 || num == 1)
        {
            if (num == 0)
                cout << "1 0" << '\n';
            else
                cout << "0 1" << '\n';
        }
        else
        {
            cout << memo[num - 1] << " " << memo[num] << '\n';
        }
    }

    return 0;
}