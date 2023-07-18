#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int T;
    int N, M;
    cin >> T;
    int answer, temp;
    while (T--)
    {
        answer = 1;
        temp = 1;
        cin >> N >> M;
        for (int i = M; i > M - N; i--)
        {
            answer *= i;
            answer /= temp++;
        }
        cout << answer << '\n';
    }
    return 0;
}