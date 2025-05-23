#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string S, T;
    cin >> S >> T;

    bool answer = false;
    while (S.size() < T.size())
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
            answer = true;
            break;
        }
    }

    cout << answer;

    return 0;
}