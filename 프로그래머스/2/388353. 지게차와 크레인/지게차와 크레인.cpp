#include <string>
#include <vector>
#include <memory.h>

using namespace std;

constexpr char clear_area = '-1';
constexpr int dir_size = 4;
int dy[dir_size] { 1, -1, 0, 0};
int dx[dir_size] { 0, 0, -1, 1};
int row_size;
int col_size;
bool visited[54][54]{};
int answer = 0;

void ClearVisited()
{
    for (int i = 0; i < col_size; i++)
    {
        memset(visited[i], 0, row_size);
    }
}

void DFS(vector<string>& storage, int pos_y, int pos_x, char find)
{
    visited[pos_y][pos_x] = true;
    
    for (int i = 0; i < dir_size; i++)
    {
        int ny = pos_y + dy[i];
        int nx = pos_x + dx[i];
        if (0 <= ny && ny < col_size && 
            0 <= nx && nx < row_size &&
            !visited[ny][nx]) 
        {
            if (storage[ny][nx] == clear_area)
                DFS(storage, ny, nx, find);
            else if (storage[ny][nx] == find)
            {
                visited[ny][nx] = true;
                storage[ny][nx] = clear_area;
                answer--;
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) 
{
    answer = storage.size() * storage[0].size();
    
    vector<string> new_storage;
    row_size = storage[0].size() + 2;
    col_size = storage.size();
    new_storage.push_back(string(row_size, clear_area));
    for (int i = 0; i < col_size; i++)
        new_storage.push_back(clear_area + storage[i] + clear_area);
    new_storage.push_back(string(row_size, clear_area));
    col_size = new_storage.size();
    
    for (int i = 0; i < requests.size(); i++) 
    {
        if (requests[i].size() == 1) 
        {
            ClearVisited();
            DFS(new_storage, 0, 0, requests[i][0]);
        }
        else 
        {
            for (auto& row : new_storage)
            {
                for (auto& val : row)
                {
                    if (val == requests[i][0]) 
                    {
                        val = clear_area;
                        answer--;
                    }
                }
            }
        }
    }
    
    return answer;
}