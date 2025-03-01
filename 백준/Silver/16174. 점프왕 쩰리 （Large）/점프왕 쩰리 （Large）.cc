#include <iostream>

using namespace std;

int map[65][65]{};
bool visited[65][65]{};

int main(void)
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }

    visited[1][1] = true;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!visited[i][j])
                continue;

            int down = i + map[i][j];
            int right = j + map[i][j];

            if (down <= N)
                visited[down][j] = true;
            if (right <= N)
                visited[i][right] = true;
        }
    }

    if (visited[N][N])
        cout << "HaruHaru";
    else
        cout << "Hing";

    return 0;
}