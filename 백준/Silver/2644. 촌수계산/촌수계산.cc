#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);

    int person1, person2;
    cin >> person1 >> person2;

    int relation;
    cin >> relation;

    for (int i = 0; i < relation; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }

    vector<bool> visited(n + 1, false);

    queue<pair<int, int>> q;
    q.push({person1, 0});
    visited[person1] = true;

    int answer = 0;
    while (!q.empty())
    {
        int person = q.front().first;
        int count = q.front().second;
        q.pop();

        if (person == person2)
        {
            answer = count;
            break;
        }

        vector<int> &relations = graph[person];

        int size = (int)relations.size();
        for (int i = 0; i < size; i++)
        {
            if (!visited[relations[i]])
            {
                q.push({relations[i], count + 1});
                visited[relations[i]] = true;
            }
        }
    }

    cout << (answer == 0 ? -1 : answer);

    return 0;
}