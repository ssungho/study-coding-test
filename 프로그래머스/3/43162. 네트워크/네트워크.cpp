#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& computers, vector<bool>& visited, int current)
{
    int size = (int)computers[current].size();
    for (int i = 0 ; i < size; i++)
    {
        if (i == current)
            continue;
        
        if (!visited[i] && computers[current][i] == 1)
        {
            visited[i] = true;
            dfs(computers, visited, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(computers, visited, i);
            answer++;
        }
    }
    
    return answer;
}