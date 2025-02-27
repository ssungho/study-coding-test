#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<bool> v(N + 1, true);
    v[0] = v[1] = false;

    vector<int> primes;

    for (int i = 2; i <= N; i++)
    {
        if (v[i])
        {
            primes.push_back(i);

            for (int j = i; j <= N; j += i)
            {
                if (j != i)
                {
                    v[j] = false;
                }
            }
        }
    }

    int primes_count = primes.size();
    vector<int> sums(primes_count + 1, 0);

    for (int i = 1; i <= primes_count; i++)
    {
        // primes는 인덱스 0부터 넣어뒀음.
        sums[i] = sums[i - 1] + primes[i - 1]; 
    }

    int start = 0;
    int end = 0;
    int count = 0;

    while (end <= primes_count)
    {
        while (sums[end] - sums[start] >= N && start < end)
        {
            if (sums[end] - sums[start] == N)
            {
                count++;
            }
            start++;
        }
        end++;
    }

    cout << count;

    return 0;
}