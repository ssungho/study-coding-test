#include <iostream>
#include <vector>
using namespace std;

constexpr int max_n{100001};
bool check[max_n]{};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    long count = 0;
    int left = 0;
    int right = 0;

    while (left < N && right < N)
    {
        if (!check[v[right]])
        {
            check[v[right]] = true;
            count += right + 1 - left;
            right++;
        }
        else
        {
            check[v[left]] = false;
            left++;
        }
    }

    cout << count << '\n';

    return 0;
}