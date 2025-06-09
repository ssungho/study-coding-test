#include <iostream>

using namespace std;

int main(void) 
{
    int count = 0;
    while (true)
    {
        int L, P, V;
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0)
            break;

        count++;

        long long mod = V % P;
        if (mod > L) mod = L;

        long long answer = V / P * L;
        answer += mod;
        cout << "Case " << count << ": " << answer << '\n';
    }

    return 0;
}