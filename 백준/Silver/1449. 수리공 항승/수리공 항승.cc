#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, L;
    cin >> N >> L;

    vector<int> pos(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());

    int start = 0;
    int end = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (pos[i] > end)
        {
            start = pos[i] - 1;
            end = start + L;
            count++;
        }
    }

    cout << count;

    return 0;
}