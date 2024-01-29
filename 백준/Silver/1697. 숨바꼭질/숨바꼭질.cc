#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
int dist[100001];

int BFS(int start, int end)
{
    visited[start] = true;
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    int cnt = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ++cnt;

        int next[3] = {cur - 1, cur + 1, cur * 2};

        for(int i = 0; i < size(next); ++i)
        {
            if(next[i] <= 100000 && next[i] >=0 && !visited[next[i]])
            {
                visited[next[i]] = true;
                dist[next[i]] = min(dist[cur] + 1, cnt);
                q.push(next[i]);
            }
        }
    }

    return dist[end];
}

int main(void)
{
    int N, K;
    cin >> N >> K;
    cout << BFS(N, K);

    return 0;
}