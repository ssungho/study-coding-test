#include <iostream>
#include <queue>

using namespace std;

bool visited[1001][1001]{};

struct INFO
{
    int count{0};
    int paste{0};
    int time{0};
};

int main(void)
{
    int S;
    cin >> S;

    queue<INFO> q;
    q.push({1, 0, 0});
    visited[1][0] = true;

    int min_time = 0;
    while (true)
    {
        INFO front = q.front();
        q.pop();

        int count = front.count;
        int paste = front.paste;
        int time = front.time;

        if (count == S)
        {
            min_time = time;
            break;
        }

        if (count > 0 && !visited[count][count])
        {
            q.push({count, count, time + 1});
            visited[count][count] = true;
        }

        if (paste > 0 && count + paste <= 1000 && !visited[count + paste][count])
        {
            q.push({count + paste, paste, time + 1});
            visited[count + paste][paste] = true;
        }

        if (count - 1 > 0 && !visited[count - 1][paste])
        {
            q.push({count - 1, paste, time + 1});
            visited[count - 1][paste] = true;
        }
    }

    cout << min_time;

    return 0;
}