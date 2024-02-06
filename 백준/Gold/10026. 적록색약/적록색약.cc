#include <iostream>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;

int picture[101][101];
bool visited[101][101];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int colors[3] = {0, 0, 0};

void BFS(int _start_x, int _start_y, int _size, int _color, bool _rg)
{
    visited[_start_x][_start_y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(_start_x, _start_y));

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (_rg)
            {
                if (nx >= 0 && ny >= 0 && nx < _size && ny < _size && !visited[nx][ny])
                {
                    if (('R' == _color || 'G' == _color) &&
                        (picture[nx][ny] == 'R' || picture[nx][ny] == 'G'))
                    {
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                    else if ((picture[nx][ny] == _color) && _color == 'B')
                    {
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
            }
            else
            {
                if (nx >= 0 && ny >= 0 && nx < _size && ny < _size &&
                    !visited[nx][ny] && (picture[nx][ny] == _color))
                {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main(void)
{
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < size; j++)
            picture[j][i] = temp[j];
    }

    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {

            if (!visited[i][j])
            {
                BFS(i, j, size, picture[i][j], false);
                count++;
            }
        }
    }

    cout << count << " ";

    memset(colors, 0, sizeof(colors));
    memset(visited, false, sizeof(visited));

    count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (!visited[i][j])
            {
                BFS(i, j, size, picture[i][j], true);
                count++;
            }
        }
    }

    cout << count;

    return 0;
}