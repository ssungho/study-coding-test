#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        string p;
        cin >> p;

        int arr_size;
        cin >> arr_size;

        string arr;
        cin >> arr;

        deque<int> dq;

        int pos = 1;
        int element = 0;

        string result = "";

        while (arr_size > 0)
        {
            if (arr[pos] == ',' || arr[pos] == ']')
            {
                dq.push_back(element);
                element = 0;
                arr_size--;
                pos++;
            }
            else
            {
                element = element * 10 + (arr[pos] - '0');
                pos++;
            }
        }

        bool is_reverse = false;
        int command_length = p.length();
        for (int i = 0; i < command_length; i++)
        {
            if (p[i] == 'R')
            {
                is_reverse = !is_reverse;
            }
            else if (p[i] == 'D')
            {
                if (dq.size() == 0)
                {
                    result = "error";
                    break;
                }

                if (is_reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (result.size() != 0)
            cout << result << '\n';
        else
        {
            if (dq.empty())
            {
                cout << "[]\n";
            }
            else
            {
                cout << '[';

                while (!dq.empty())
                {
                    if (is_reverse)
                    {
                        cout << dq.back();
                        dq.pop_back();
                    }
                    else
                    {
                        cout << dq.front();
                        dq.pop_front();
                    }

                    if (dq.empty())
                        cout << "]\n";
                    else
                        cout << ',';
                }
            }
        }
    }

    return 0;
}