#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

char arr[51][51];
bool visited[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int y, int x, int K)
{
    char current_char = arr[y][x];
    vector<pair<int, int>> pos;
    queue<pair<int, int>> q;

    q.push({y, x});
    pos.push_back({y, x});
    visited[y][x] = true;

    int cnt = 1;
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + current.first;
            int nx = dx[i] + current.second;
            if (ny > 0 && nx > 0 && ny < 51 && nx < 51 && !visited[ny][nx] && arr[ny][nx] == current_char)
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
                pos.push_back({ny, nx});
                cnt++;
            }
        }
    }

    if (cnt >= K)
        for (int i = 0; i < pos.size(); i++)
            arr[pos[i].first][pos[i].second] = '.';
}
int main(void)
{
    // 배열의 크기, 연결 요소를 지울 기준, 문자를 적을 횟수
    int N, K, Q;
    cin >> N >> K >> Q;

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            char temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int y, x;
        char ch;
        // 문자 지정
        cin >> y >> x >> ch;
        arr[y][x] = ch;
        visited[y][x] = false;

        // 요소 크기 확인
        for (int j = 1; j < N + 1; j++)
        {
            for (int k = 1; k < N + 1; k++)
            {
                if (!visited[j][k])
                {
                    BFS(j, k, K);
                }
            }
        }
        memset(visited, false, sizeof(visited));
    }
    
    // 요소 출력
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            cout << arr[i][j];
            if (j == N)
                cout << '\n';
        }
    }
    return 0;
}