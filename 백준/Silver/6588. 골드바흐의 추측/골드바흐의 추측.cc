#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> numbers(1000001, true);

void Test(int x)
{
    for (int i = 3; i <= 1000000; i += 2)
    {
        if (numbers[i] && numbers[x - i])
        {
            cout << x << " = " << i << " + " << x - i << '\n';
            return;
        }
    }

    cout << "Goldbach's conjecture is wrong.\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    numbers[0] = numbers[1] = false;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (numbers[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                numbers[j] = false;
            }
        }
    }

    while (true)
    {
        int N;
        cin >> N;

        if (N == 0)
            break;

        Test(N);
    }

    return 0;
}