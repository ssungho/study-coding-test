#include<vector>
#include<queue>

using namespace std;

constexpr int DIR_SIZE{4};
int dy[DIR_SIZE]{-1, 1, 0, 0};
int dx[DIR_SIZE]{0, 0, -1, 1};

int bfs(vector<vector<int>>& maps)
{
    using CNT_POS = pair<int, pair<int, int>>;
 
    int count = -1;
    int N = (int)maps.size();
    int M = (int)maps[0].size();
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<CNT_POS> q;
    
    q.push({1, {0, 0}});
    visited[0][0] = true;
    
    while (!q.empty()) 
    {
        int current_count = q.front().first;
        int current_y = q.front().second.first;
        int current_x = q.front().second.second;
        q.pop();
        
        if (current_y == N - 1 && 
            current_x == M - 1)
        {
            count = current_count;
            break;
        }
        
        for (int i = 0; i < DIR_SIZE; i++)
        {
            int ny = current_y + dy[i];
            int nx = current_x + dx[i];
            
            if (0 <= ny && ny < N && 0 <= nx && nx < M &&
                !visited[ny][nx] && maps[ny][nx] == 1) 
            {
                q.push({current_count + 1, {ny, nx}});
                visited[ny][nx] = true;
            }
        }
    }
    
    return count;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = bfs(maps);
    return answer;
}