#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int sum = 0;
    while (!pq.empty())
    {
        int count = 0;
        count += pq.top();
        pq.pop();

        if (pq.empty())
        {
            break;
        }

        count += pq.top();
        pq.pop();

        sum += count;

        pq.push(count);
    }

    cout << sum;

    return 0;
}