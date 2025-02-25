#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int graph[101]{};
    bool visited[101]{};
    map<int, int> ladders;
    map<int, int> snakes;

    for (int i = 0; i < N; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        ladders.insert(p);
    }

    for (int i = 0; i < M; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        snakes.insert(p);
    }

    queue<int> q;
    graph[1] = 0;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int next = current + i;

            auto ladder = ladders.end();
            auto snake = snakes.end();

            if (ladder != ladders.find(next))
            {
                next = ladders[next];
            }
            else if (snake != snakes.find(next))
            {
                next = snakes[next];
            }

            if ((next <= 100) && !visited[next])
            {
                q.push(next);
                graph[next] = graph[current] + 1;
                visited[next] = true;
            }
        }
    }

    cout << graph[100];

    return 0;
}