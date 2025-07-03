#include <iostream>
#include <queue>
#include <climits>

using namespace std;

constexpr int MIN_FLOOR{1};
constexpr int MAX_FLOOR{1000000};
bool visited[MAX_FLOOR + 1]{};
int F, G, S, U, D;

int BFS()
{
    int result = INT_MAX;
    queue<pair<int, int>> q;
    q.push({S, 0});
    visited[S] = true;

    while (!q.empty())
    {
        int pos = q.front().first;
        int count = q.front().second;
        q.pop();

        if (pos == G)
        {
            return count;
        }

        int up = pos + U;
        if (MIN_FLOOR <= up && up <= F && !visited[up])
        {
            visited[up] = true;
            q.push({up, count + 1});
        }

        int down = pos - D;
        if (MIN_FLOOR <= down && down <= F && !visited[down])
        {
            visited[down] = true;
            q.push({down, count + 1});
        }
    }

    return result;
}

int main(void)
{
    cin >> F >> S >> G >> U >> D;

    int result = BFS();

    if (!visited[G])
    {
        cout << "use the stairs \n";
    }
    else
    {
        cout << result << '\n';
    }

    return 0;
}