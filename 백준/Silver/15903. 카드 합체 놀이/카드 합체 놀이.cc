#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> cards;
    for (int i = 0; i < n; i++)
    {
        long long number;
        cin >> number;
        cards.push(number);
    }

    while (m--)
    {
        long long sum = 0;
        for (int i = 0; i < 2; i++)
        {
            sum += cards.top();
            cards.pop();
        }

        cards.push(sum);
        cards.push(sum);
    }

    long long sum = 0;
    while (!cards.empty())
    {
        sum += cards.top();
        cards.pop();
    }

    cout << sum;

    return 0;
}