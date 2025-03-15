#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool error_buttons[10]{};
int min_press{};
int channel{};

void Find(int number, int size)
{
    for (int i = 0; i <= 1000000; i++)
    {
        string number_string = to_string(i);
        bool check = true;

        int cur_size = number_string.size();
        for (int j = 0; j < cur_size; j++)
        {
            if (error_buttons[int(number_string[j] - '0')])
            {
                check = false;
                break;
            }
        }

        if (check)
        {
            min_press = min(abs(number - i) + cur_size, min_press);
        }

    }

    min_press = min(min_press, abs(number - 100));
}

int main(void)
{
    string N;
    cin >> N;
    channel = stoi(N);

    int M;
    cin >> M;

    if (M == 0)
    {
        min_press = abs(100 - channel) < N.size() ? abs(100 - channel) : N.size();
        cout << min_press;
        return 0;
    }

    for (int i = 0; i < M; i++)
    {
        int error_button;
        cin >> error_button;

        error_buttons[error_button] = true;
    }

    int size = N.size();

    min_press = abs(channel - 100);

    Find(channel, size);

    cout << min_press;

    return 0;
}