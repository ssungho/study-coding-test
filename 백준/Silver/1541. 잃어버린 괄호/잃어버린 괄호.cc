#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string input;
    cin >> input;

    int temp = 0;
    int add_sum = 0;
    int minus_sum = 0;
    bool minus = false;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '+')
        {
            if (minus)
                minus_sum += temp;
            else
                add_sum += temp;
            temp = 0;
        }
        else if (input[i] == '-')
        {
            if (minus)
                minus_sum += temp;
            else
            {
                add_sum += temp;
                minus = true;
            }
            temp = 0;
        }
        else
        {
            temp *= 10;
            temp += (input[i] - '0');
        }

        if (i == input.length() - 1)
        {
            if (minus)
                minus_sum += temp;
            else
                add_sum += temp;
        }
    }

    cout << add_sum - minus_sum;
    return 0;
}