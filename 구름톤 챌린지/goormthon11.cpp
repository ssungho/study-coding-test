#include <iostream>
using namespace std;

int Find(int &N, int &A, int &B)
{
    int answer = 0;
    if (N >= B)
    {
        answer += N / B;
        N %= B;
    }
    if (N >= A)
    {
        answer += N / A;
        N %= A;
    }
    if (N == 0)
        return answer;

    while (answer > 0)
    {
        answer--;
        N += B;
        if ((N % A) == 0)
        {
            answer += N / A;
            return answer;
        }
    }
    return -1;
}

int main(void)
{
    int N, A, B;
    cin >> N >> A >> B;
    cout << Find(N, A, B);

    return 0;
}