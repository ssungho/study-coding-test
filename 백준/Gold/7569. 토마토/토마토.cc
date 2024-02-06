#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, h;

int box[101][101][101];
int days[101][101][101];
int visited[101][101][101];

// 위 중간 아래
int dh[6] = {1, 0, 0, 0, 0, -1};
int dn[6] = {0, -1, 1, 0, 0, 0};
int dm[6] = {0, 0, 0, -1, 1, 0};

struct pos
{
    int h = 0, n = 0, m = 0;
};

int BFS(queue<pos> &start)
{
    if (start.size() == m * n * h)
        return 0;

    int min_day = 0;

    queue<pos> q;
    while(!start.empty())
    {
        pos temp = start.front();
        q.push(temp);
        visited[temp.h][temp.n][temp.m] = true;
        start.pop();
    }

    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nh = cur.h + dh[i];
            int nn = cur.n + dn[i];
            int nm = cur.m + dm[i];

            if (nh < h && nn < n && nm < m &&
                nh >= 0 && nn >= 0 && nm >= 0 &&
                box[nh][nn][nm] != -1 &&
                !visited[nh][nn][nm])
            {
                visited[nh][nn][nm] = true;
                q.push({nh, nn, nm});
                days[nh][nn][nm] = days[cur.h][cur.n][cur.m] + 1;
                min_day = max(min_day, days[nh][nn][nm]);
            }
        }
    }

    bool can = true;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
                if (box[i][j][k] != -1 && !visited[i][j][k])
                    can = false;

    if (can)
        return min_day;
    else
        return -1;
}

int main()
{
    cin >> m >> n >> h;

    queue<pos> q;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                cin >> box[i][j][k];
                days[i][j][k] = -1;
                if (box[i][j][k] == 1)
                {
                    days[i][j][k] = 0;
                    q.push({i, j, k});
                }
            }

    cout << BFS(q);

    return 0;
}