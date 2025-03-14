#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> permutation(N);

    for (int i = 0; i < N; i++)
    {
        cin >> permutation[i];
    }

    for (int i = N - 1; i > 0; i--)
    {
        if (permutation[i - 1] < permutation[i])
        {
            for (int j = N - 1; j >= i; j--)
            {
                if (permutation[i - 1] < permutation[j])
                {
                    swap(permutation[i - 1], permutation[j]);

                    int k = N - 1;
                    while (i < k)
                    {
                        swap(permutation[i], permutation[k]);
                        i++;
                        k--;
                    }

                    for (auto ele : permutation)
                    {
                        cout << ele << " ";
                    }

                    return 0;
                }
            }
        }
    }

    cout << -1;

    return 0;
}