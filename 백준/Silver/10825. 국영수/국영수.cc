#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Score
{
private:
    int kor;
    int eng;
    int mat;
    string name;

public:
    void InputInfo()
    {
        cin >> name >> kor >> eng >> mat;
    }
    void PrintName()
    {
        cout << name;
    }

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<Score> scores(N);
    for (auto &score : scores)
    {
        score.InputInfo();
    }

    sort(scores.begin(), scores.end());

    for (auto &score : scores)
    {
        score.PrintName();
        cout << '\n';
    }

    return 0;
}