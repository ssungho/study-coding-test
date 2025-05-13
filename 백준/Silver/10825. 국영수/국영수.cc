#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Score
{
    int kor;
    int eng;
    int mat;
    string name;

    bool operator<(const Score &other)
    {
        if (kor == other.kor)
        {
            if (eng == other.eng)
            {
                if (mat == other.mat)
                {
                    return name < other.name;
                }

                return mat > other.mat;
            }

            return eng < other.eng;
        }

        return kor > other.kor;
    }
};

int main(void)
{
    int N;
    cin >> N;

    vector<Score> scores(N);
    for (auto &score : scores)
    {
        cin >> score.name;
        cin >> score.kor;
        cin >> score.eng;
        cin >> score.mat;
    }

    sort(scores.begin(), scores.end());

    for (auto &score : scores)
    {
        cout << score.name << '\n';
    }

    return 0;
}