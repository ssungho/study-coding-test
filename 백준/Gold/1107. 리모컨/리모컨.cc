#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool error_buttons[10]{};
int min_press;
int channel{};

void Find(int number)
{
    for (int i = 0; i <= 1000000; i++)
    {
        string number_string = to_string(i);
        bool check = true;

        for (char c : number_string)
        {
            if (error_buttons[c - '0'])
            {
                check = false;
                break;
            }
        }

        if (check)
        {
            int press_count = abs(number - i) + number_string.size();
            min_press = min(min_press, press_count);
        }
    }
}

int main(void)
{
    cin >> channel;

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int error_button;
        cin >> error_button;
        error_buttons[error_button] = true;
    }

    min_press = abs(channel - 100);

    Find(channel);

    cout << min_press;

    return 0;
}