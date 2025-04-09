#include <iostream>
#include <queue>

using namespace std;

const int length = 100000;

int main(void)
{
    int N, K;
    cin >> N >> K;

    if (N == K) 
    {
        cout << 0 << '\n' << 1;
        return 0;
    }

    vector<int> visited(length + 1, -1);
    vector<int> counts(length + 1, 0);
    queue<int> q;

    q.push(N);
    visited[N] = 0;

    while (true)
    {
        int pos = q.front();
        q.pop();

        if (pos == K)
            break;

        int next = pos + 1;
        int prev = pos - 1;
        int mult = pos * 2;

        if (next <= length && (-1 == visited[next] || visited[pos] + 1 == visited[next]))
        {
            q.push(next);
            visited[next] = visited[pos] + 1;
            counts[next]++;
        }

        if (prev >= 0 && (-1 == visited[prev] || visited[pos] + 1 == visited[prev]))
        {
            q.push(prev);
            visited[prev] = visited[pos] + 1;
            counts[prev]++;
        }

        if (mult <= length && (-1 == visited[mult] || visited[pos] + 1 == visited[mult]))
        {
            q.push(mult);
            visited[mult] = visited[pos] + 1;
            counts[mult]++;
        }
    }

    cout << visited[K] << '\n' << counts[K];

    return 0;
}