#include <iostream>
#include <string>

using namespace std;

string MakeTime(int time)
{
    string m = to_string(time / 60);
    while (m.size() < 2)
    {
        m = '0' + m;
    }

    string s = to_string(time % 60);
    while (s.size() < 2)
    {
        s = '0' + s;
    }

    return m + ':' + s;
}

int main(void)
{
    int N;
    cin >> N;

    int team1 = 0;
    int team2 = 0;
    int time1 = 0;
    int time2 = 0;
    string prev = "00:00";
    bool flag = false;

    for (int i = 0; i < N; i++)
    {
        int team;
        string time;
        cin >> team >> time;

        (team == 1) ? team1++ : team2++;

        int m = ((time[0] - prev[0]) * 10 + (time[1] - prev[1])) * 60;
        int s = m + (time[3] - prev[3]) * 10 + (time[4] - prev[4]);

        if (team1 == team2 && team == 1)
        {
            time2 += s;
            prev = time;
            flag = false;
        }
        else if (team1 == team2 && team == 2)
        {
            time1 += s;
            prev = time;
            flag = false;
        }
        else if (team1 != team2 && !flag)
        {
            prev = time;
            flag = true;
        }
    }

    int m = (('4' - prev[0]) * 10 + ('7' - prev[1])) * 60;
    int s = m + ('6' - prev[3]) * 10 + ('0' - prev[4]);

    if (team1 > team2)
        time1 += s;
    if (team1 < team2)
        time2 += s;

    cout << MakeTime(time1) << '\n';
    cout << MakeTime(time2) << '\n';

    return 0;
}