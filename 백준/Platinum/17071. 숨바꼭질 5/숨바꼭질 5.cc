#include <iostream>
#include <queue>

using namespace std;

constexpr int max_pos{500000};
bool visited[max_pos + 1][2]{};
int N, K;

int Search()
{
    queue<int> q;
    q.push(N);
    visited[N][0] = true;
    int time = 0;

    while (!q.empty())
    {
        int target = K + time * (time + 1) / 2;

        if (target > max_pos)
        {
            return -1;
        }

        if (visited[target][time % 2])
        {
            return time;
        }

        size_t size = q.size();
        for (size_t i = 0; i < size; i++)
        {
            int current_pos = q.front();
            q.pop();

            int next_pos = current_pos + 1;
            int next_time = (time + 1) % 2;

            if (0 <= next_pos && next_pos <= max_pos && !visited[next_pos][next_time])
            {
                visited[next_pos][next_time] = true;
                q.push(next_pos);
            }

            next_pos = current_pos - 1;
            if (0 <= next_pos && next_pos <= max_pos && !visited[next_pos][next_time])
            {
                visited[next_pos][next_time] = true;
                q.push(next_pos);
            }

            next_pos = current_pos * 2;
            if (0 <= next_pos && next_pos <= max_pos && !visited[next_pos][next_time])
            {
                visited[next_pos][next_time] = true;
                q.push(next_pos);
            }
        }

        time++;
    }

    return -1;
}

int main(void)
{
    cin >> N >> K;

    cout << Search();

    return 0;
}