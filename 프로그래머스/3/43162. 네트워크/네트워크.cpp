#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>>& nodes, vector<bool>& visited, int node)
{
    vector<int>& neighbors = nodes[node];
    
    for (int neighbor : neighbors)
    {
        if (!visited[neighbor])
        {
            visited[neighbor] = true;
            dfs(nodes, visited, neighbor);
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    vector<vector<int>> nodes(n);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (computers[i][j] == 1)
            {
                nodes[i].push_back(j);
                nodes[j].push_back(i);
            }
        }
    }
    
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(nodes, visited, i);
            answer++;
        }
    }
    
    return answer;
}