#include <iostream>

using namespace std;

int n;

bool IsPrime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

void DFS(int num, int count)
{
    if (count == n)
    {
        if (IsPrime(num))
        {
            cout << num << '\n';
        }

        return;
    }

    for (int i = 1; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }

        if (IsPrime(num * 10 + i))
        {
            DFS(num * 10 + i, count + 1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    return 0;
}