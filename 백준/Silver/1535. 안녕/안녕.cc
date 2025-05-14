#include <iostream>

using namespace std;

int N = 0;
int max_joy = 0;

void Tracking(int *L, int *J, bool *visited, int index, int life, int joy)
{
    max_joy = max(max_joy, joy);

    for (int i = index; i < N; i++)
    {
        int next_life = life - L[i];

        if (next_life > 0 && !visited[i])
        {
            visited[i] = true;
            Tracking(L, J, visited, i + 1, next_life, joy + J[i]);
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> N;

    int L[20]{};
    int J[20]{};
    bool visited[20]{};

    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> J[i];
    }

    Tracking(L, J, visited, 0, 100, 0);

    cout << max_joy;

    return 0;
}