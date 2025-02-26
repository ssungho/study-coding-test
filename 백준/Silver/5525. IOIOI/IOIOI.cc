#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int N, M;
    string S;

    cin >> N >> M >> S;

    string find = "I";

    for (int i = 0; i < N; i++)
        find += "OI";

    int count = 0;
    int start = 0;
    int length = find.length();

    while (start + length <= M)
    {
        size_t pos = S.find(find, start);

        if (pos != string::npos)
        {
            count++;
            start = pos + 1;
        }
        else
            start++;
    }

    cout << count;

    return 0;
}