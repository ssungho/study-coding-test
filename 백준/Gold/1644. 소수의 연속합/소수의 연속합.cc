#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<bool> is_prime(N + 1, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);

            for (int j = i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    int count = 0;
    int prime_count = (int)primes.size();
    for (int i = 0; i < prime_count; i++)
    {
        int j = i;
        int acc = 0;
        while (j >= 0)
        {
            acc += primes[j];

            if (acc == N)
            {
                count++;
                break;
            }
            else if (acc > N)
            {
                break;
            }

            j--;
        }
    }

    cout << count << '\n';

    return 0;
}