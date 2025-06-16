#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int dir_size{4};
int dy[dir_size]{-1, 1, 0, 0};
int dx[dir_size]{0, 0, -1, 1};
int R, C;

queue<pair<int, int>> swan_q, next_swan_q;
queue<pair<int, int>> water_q, next_water_q;

bool MoveSwan(vector<vector<char>>& lake, vector<vector<bool>>& visited)
{
    while (!swan_q.empty())
    {
        int current_y = swan_q.front().first;
        int current_x = swan_q.front().second;
        swan_q.pop();

        for (int dir = 0; dir < dir_size; dir++)
        {
            int ny = dy[dir] + current_y;
            int nx = dx[dir] + current_x;

            if (0 <= ny && ny < R && 0 <= nx && nx < C && !visited[ny][nx])
            {
                visited[ny][nx] = true;

                if (lake[ny][nx] == 'X')
                {
                    next_swan_q.push({ny, nx});
                }
                else if (lake[ny][nx] == '.')
                {
                    swan_q.push({ny, nx});
                }
                else if (lake[ny][nx] == 'L')
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void Melt(vector<vector<char>>& lake, vector<vector<bool>>& visited)
{
  while (!water_q.empty())
    {
        int current_y = water_q.front().first;
        int current_x = water_q.front().second;
        water_q.pop();

        for (int dir = 0; dir < dir_size; dir++)
        {
            int ny = dy[dir] + current_y;
            int nx = dx[dir] + current_x;

            if (0 <= ny && ny < R && 0 <= nx && nx < C && !visited[ny][nx])
            {
                if (lake[ny][nx] == 'X')
                {
                    visited[ny][nx] = true;
                    next_water_q.push({ny, nx});
                    lake[ny][nx] = '.';
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    vector<vector<char>> lake(R, vector<char>(C, '.'));
    vector<vector<bool>> swan_visited(R, vector<bool>(C, false));
    vector<vector<bool>> water_visited(R, vector<bool>(C, false));
    int swan_y, swan_x;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> lake[i][j];

            if (lake[i][j] == 'L')
            {
                swan_y = i;
                swan_x = j;
            }
            
            if (lake[i][j] == 'L' || lake[i][j] == '.')
            {
                water_q.push({i, j});
                water_visited[i][j] = true;
            }
        }
    }

    int count = 0;
    swan_q.push({swan_y, swan_x});
    swan_visited[swan_y][swan_x] = true;

    while(true) 
    {
        if (MoveSwan(lake, swan_visited)) 
        {
            break;
        }

        Melt(lake, water_visited);
        swan_q = next_swan_q;
        water_q = next_water_q;

        queue<pair<int, int>>().swap(next_swan_q);
        queue<pair<int, int>>().swap(next_water_q);

        count++;
    }
   
    cout << count << '\n';

    return 0;
}