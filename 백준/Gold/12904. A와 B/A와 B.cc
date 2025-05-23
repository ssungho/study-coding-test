#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string S, T;
    cin >> S >> T;

    bool answer = true;
    while (true)
    {
        if (T.back() == 'A')
        {
            T.pop_back();
        }
        else
        {
            T.pop_back();
            reverse(T.begin(), T.end());
        }

        if (S == T)
        {
            break;
        }
        else
        {
            if (T.empty() || S.size() > T.size())
            {
                answer = false;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}