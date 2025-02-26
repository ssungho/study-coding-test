#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int N, M;
    string S;

    cin >> N >> M >> S;

    int count = 0;
    int find = 0;

    for (int i = 1; i < M - 1; i++)
    {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I')
        {
            find++;

            if (find >= N)
                count++;

            i++;
        }
        else
        {
            find = 0;
        }
    }

    cout << count;

    return 0;
}