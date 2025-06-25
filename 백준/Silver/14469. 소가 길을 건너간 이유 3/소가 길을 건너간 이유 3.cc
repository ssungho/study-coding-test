#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    int N;
    cin >> N;

    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    int sec = 0;

    for (int i = 0; i < N; i++) 
    {
        if (sec < cows[i].first)
        {
            sec = (cows[i].first + cows[i].second);
        }
        else
        {
            sec += cows[i].second;
        }
    }

    cout << sec << '\n';

    return 0;
}