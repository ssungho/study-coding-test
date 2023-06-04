#include <iostream>
#include <string>

using namespace std;

int main()
{
    int scores = 20;
    float sum1 = 0;
    float sum2 = 0;

    for (int i = 0; i < scores; i++)
    {
        string subject;
        float score1;
        string score2;
        float f_score2 = 0.0;

        cin >> subject >> score1 >> score2;

        if (score2 == "A+")
            f_score2 = 4.5;

        if (score2 == "A0")
            f_score2 = 4.0;

        if (score2 == "B+")
            f_score2 = 3.5;

        if (score2 == "B0")
            f_score2 = 3.0;

        if (score2 == "C+")
            f_score2 = 2.5;

        if (score2 == "C0")
            f_score2 = 2.0;

        if (score2 == "D+")
            f_score2 = 1.5;

        if (score2 == "D0")
            f_score2 = 1.0;

        if (score2 == "F")
            f_score2 = 0.0;

        if (score2 == "P")
            continue;
        else
        {
            sum1 += score1;
            sum2 += score1 * f_score2;
        }
    }

    cout << sum2 / sum1;

    return 0;
}