#include <iostream>
#include <queue>
#include <stack>

using namespace std;
constexpr int max_pos{100000};
pair<bool, int> visited[max_pos + 1]{};

int N, K;

int Search()
{
    queue<int> q;
    q.push(N);
    visited[N] = {true, -1};

    int time = 0;

    while (!q.empty())
    {
        size_t size = q.size();
        for (size_t i = 0; i < size; i++)
        {
            int current_pos = q.front();
            q.pop();

            if (current_pos == K)
            {
                return time;
            }

            for (auto next_pos : {current_pos - 1, current_pos + 1, current_pos * 2})
            {
                if (0 <= next_pos && next_pos <= max_pos && !visited[next_pos].first)
                {
                    visited[next_pos] = {true, current_pos};
                    q.push(next_pos);
                }
            }
        }

        time++;
    }

    return time;
}

int main(void)
{
    cin >> N >> K;

    cout << Search() << '\n';

    stack<int> s;

    int path = K;

    while (path != -1)
    {
        s.push(path);
        path = visited[path].second;
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}