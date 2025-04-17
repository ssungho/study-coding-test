#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int DIR_SIZE{8};
int dy[DIR_SIZE]{2, 1, -1, -2, -2, -1, 1, 2};
int dx[DIR_SIZE]{1, 2, 2, 1, -1, -2, -2, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; 
    cin >> T;
    
    while (T--) 
    {
        int size;
        cin >> size;

        pair<int, int> start, dest;
        cin >> start.first >> start.second >> dest.first >> dest.second;

        vector<vector<bool>> visited(size, vector<bool>(size, false));
        queue<pair<pair<int, int>, int>> q;

        q.push({start, 0});
        visited[start.first][start.second] = true;

        int answer = 0;

        while (!q.empty())
        {
            pair<pair<int, int>, int> front = q.front();
            int current_x = front.first.first;
            int current_y = front.first.second;
            int move_count = front.second;
            q.pop();

            if (current_x == dest.first && current_y == dest.second) 
            {
                answer = move_count;
                break;
            }

            for (int i = 0; i < DIR_SIZE; i++) 
            {
                int nx = dx[i] + current_x;
                int ny = dy[i] + current_y;

                if (nx >= 0 && nx < size && ny >= 0 && ny < size && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, move_count + 1});
                }
            }
        }
    
        cout << answer << '\n';
    }

    return 0;
}