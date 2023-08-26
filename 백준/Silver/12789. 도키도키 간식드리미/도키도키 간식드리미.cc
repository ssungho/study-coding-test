#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(void)
{
    queue<int> line;
    stack<int> wait;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        line.push(temp);
    }

    for (int i = 1; i < n + 1; i++)
    {
        // 만약 현재 순서가 맞지 않으면 스택에 넣는다.
        // 현재 순서가 맞으면 큐에서 제거
        if (!wait.empty() && wait.top() == i)
        {
            wait.pop();
        }
        else
        {
            while (!line.empty())
            {
                if (!line.empty() && line.front() != i)
                {
                    wait.push(line.front());
                    line.pop();
                }
                else if (!line.empty() && line.front() == i)
                {
                    line.pop();
                    break;
                }
            }
        }
    }

    if (wait.empty() && line.empty())
        cout << "Nice";
    else
        cout << "Sad";
    return 0;
}