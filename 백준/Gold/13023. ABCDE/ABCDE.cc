#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool exist = false;

void Backtracking(vector<vector<int>> &graph, vector<bool> &visited, int count, int person)
{
    if (exist)
    {
        return;
    }

    if (count >= 5)
    {
        exist = true;
        return;
    }

    vector<int> &friends = graph[person];
    int size = friends.size();
    for (int i = 0; i < size; i++)
    {
        if (!visited[friends[i]])
        {
            visited[friends[i]] = true;

            Backtracking(graph, visited, count + 1, friends[i]);

            visited[friends[i]] = false;
        }
    }
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    vector<bool> visited(N);

    for (int i = 0; i < M; i++)
    {
        int person1, person2;
        cin >> person1 >> person2;
        graph[person1].push_back(person2);
        graph[person2].push_back(person1);
    }

    for (int i = 0; i < N; i++)
    {
        Backtracking(graph, visited, 0, i);

        if (exist)
        {
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}