#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, score, p;
    cin >> n >> score >> p;

    if (n == 0)
    {
        cout << 1;
        return 0;
    }

    vector<int> scores;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        scores.push_back(temp);
    }

    int rank = 1, same = 0;
    for (int i = 0; i < scores.size() + 1; i++)
    {
        if (scores[i] < score || scores.size() == i)
        {
            if (rank + same <= p)
                cout << rank;
            else
                cout << -1;
            return 0;
        }
        else if (scores[i] > score)
            rank++;
        else if (scores[i] == score)
            same++;
    }

    cout << -1;
    return 0;
}