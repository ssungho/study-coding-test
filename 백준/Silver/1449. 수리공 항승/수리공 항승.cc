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

    int end = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (pos[i] > end)
        {
            end =  pos[i] - 1 + L;
            count++;
        }
    }

    cout << count;

    return 0;
}