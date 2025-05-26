#include <string>
#include <vector>
#include <queue>

using namespace std;

constexpr int MAX_SIZE{102};
constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{1, -1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};

int solution(vector<vector<int>> rectangle, 
             int characterX, int characterY, 
             int itemX, int itemY) 
{
    int answer = 0;
    
    vector<vector<int>> paths(MAX_SIZE, vector<int>(MAX_SIZE, 2));
    
    for (auto& pos : rectangle)
    {
        for (int i = 0; i < 4; i++)
        {
            pos[i] *= 2;
        }
        
        for (int i = pos[1]; i <= pos[3]; i++)
        {
            for (int j = pos[0]; j <= pos[2]; j++)
            {
                if (i == pos[1]|| i == pos[3] ||
                    j == pos[0]|| j == pos[2])
                {
                    if (paths[i][j] == 2)
                        paths[i][j] = 1;
                }
                else
                {
                    paths[i][j] = 0;
                }
            }
        }
    }
    
    characterY *= 2;
    characterX *= 2;
    itemY *= 2;
    itemX *= 2;
    
    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> visited(MAX_SIZE, vector<bool>(MAX_SIZE, false));
    q.push({0, {characterY, characterX}});
    visited[characterY][characterX] = true;
    
    while (!q.empty())
    {
        int current_dist = q.front().first;
        int current_y = q.front().second.first;
        int current_x = q.front().second.second;
        q.pop();
        
        if (current_y == itemY && current_x == itemX)
        {
            answer = current_dist / 2;
            break;
        }
        
        for (int i = 0; i < DIR_SIZE; i++)
        {
            int ny = dy[i] + current_y;
            int nx = dx[i] + current_x;
            
            if (0 < ny && ny < MAX_SIZE && 
                0 < nx && nx < MAX_SIZE &&
                !visited[ny][nx] && paths[ny][nx] == 1)
            {
                q.push({current_dist + 1, {ny, nx}});
                visited[ny][nx] = true;
            }
        }
    }
    
    return answer;
}