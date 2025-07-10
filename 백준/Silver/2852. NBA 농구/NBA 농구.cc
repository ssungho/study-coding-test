#include <iostream>
#include <string>

using namespace std;

string MakeTimeToString(int time)
{
    string m = "00" + to_string(time / 60);
    string s = "00" + to_string(time % 60);
    return m.substr(m.size() - 2, 2) + ':' + s.substr(s.size() - 2, 2);
}

int StringToInt(string str)
{
    return atoi(str.substr(0, 2).c_str()) * 60 + atoi(str.substr(3, 2).c_str());
}

void Go(int& sum, string str, string prev)
{
    sum += StringToInt(str) - StringToInt(prev);
}

int main(void)
{
    int N;
    cin >> N;

    int team1{}, team2{};
    int team1_sum{}, team2_sum{};
    string prev = "";

    for (int i = 0; i < N; i++)
    {
        int team;
        string time;
        cin >> team >> time;

        if (team1 > team2)
            Go(team1_sum, time, prev);
        else if (team1 < team2)
            Go(team2_sum, time, prev);

        (team == 1) ? team1++ : team2++;
        prev = time;
    }

    if (team1 > team2)
        Go(team1_sum, "48:00", prev);
    else if (team1 < team2)
        Go(team2_sum, "48:00", prev);

    cout << MakeTimeToString(team1_sum) << '\n';
    cout << MakeTimeToString(team2_sum) << '\n';

    return 0;
}