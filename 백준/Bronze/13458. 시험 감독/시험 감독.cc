#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<long> v(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    long B, C;
    cin >> B >> C;

    long total = N;

    for (auto &i : v)
    {
        i -= B;
        if (i > 0)
        {
            if (i % C != 0)
            {
                total += 1;
            }

            total += long(i / C);
        }
    }

    cout << total;

    return 0;
}