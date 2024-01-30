#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int box[1001][1001];
bool visited[1001][1001];
int day[1001][1001];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int m, n;

int BFS(vector<pair<int, int>> start)
{
    if (start.size() == n * m)
        return 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < start.size(); i++)
    {
        q.push(start[i]);
        visited[start[i].first][start[i].second] = true;
    }

    int min_day = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[ny][nx] && box[ny][nx] != -1)
            {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                day[ny][nx] = day[cur.first][cur.second] + 1;
                min_day = max(min_day, day[ny][nx]);
            }
        }
    }

    bool can = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (box[i][j] != -1 && !visited[i][j])
                can = false;

    if (can)
        return min_day;
    else
        return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];
            day[i][j] = -1;
            if (box[i][j] == 1)
            {
                day[i][j] = 0;
                v.push_back(make_pair(i, j));
            }
        }
    }

    cout << BFS(v);

    return 0;
}