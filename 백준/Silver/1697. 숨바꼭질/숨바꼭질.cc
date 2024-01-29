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
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        ++cnt;
        
        int next;
        if(cur - 1  >= 0 && !visited[cur - 1])
        {
            next = cur - 1;
            visited[next] = true;
            dist[next] = min(dist[cur] + 1, cnt); 
            q.push(next);
        }
        if(cur + 1  <= 100000 && !visited[cur + 1])
        {
            next = cur + 1;
            visited[next] = true;
            dist[next] = min(dist[cur] + 1, cnt); 
            q.push(next);
        }
        if(cur * 2 <= 100000 && !visited[cur * 2])
        {
            next = cur * 2;
            visited[next] = true;
            dist[next] = min(dist[cur] + 1, cnt); 
            q.push(next);
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