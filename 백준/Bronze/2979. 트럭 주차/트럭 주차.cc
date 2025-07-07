#include <iostream>

using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;
    
    int cnt[101] = {};
    for (int i = 0; i < 3; i++)
    {
        int start, end;
        cin >> start >> end;
        for (; start < end; start++)
        {
            cnt[start]++;
        }
    }

    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (cnt[i] == 1)
            sum += A;
        else if (cnt[i] == 2)
            sum += B * 2;
        else if (cnt[i] == 3)
            sum += C * 3;
    }

    cout << sum << '\n';

    return 0;
}