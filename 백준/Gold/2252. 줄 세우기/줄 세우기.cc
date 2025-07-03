#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> in_degrees(N + 1, 0);
    vector<vector<int>> students(N + 1);
    for (int i = 0; i < M; i++)
    {
        int front, back;
        cin >> front >> back;
        students[front].push_back(back);
        in_degrees[back]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (in_degrees[i] == 0)
        {
            q.push(i);
        }
    }

    while (q.size())
    {
        auto front = q.front();
        q.pop();

        cout << front << '\n';

        auto& adj = students[front];
        for (auto i : adj)
        {
            if (--in_degrees[i] == 0)
            {
                q.push(i);
            }
        }
    }

    return 0;
}