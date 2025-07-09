#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) 
{
    int N;
    cin >> N;

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        stack<char> s;
        string word;
        cin >> word;

        for (auto ch : word)
        {
            if (s.empty())
            {
                s.push(ch);
                continue;
            }

            if (s.top() != ch)
                s.push(ch);
            else
                s.pop();
        }

        if (s.empty())
            answer++;
    }

    cout << answer << '\n';

    return 0;
}