#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> v;
    v.reserve(N);

    for (int i = 0; i < N; i++)
    {
        int fruit;
        cin >> fruit;
        v.push_back(fruit);
    }

    int left = 0, right = 0;
    int max_length = 0;
    map<int, int> counter;

    while (right < N)
    {
        counter[v[right]]++;
        while (counter.size() > 2)
        {
            counter[v[left]]--;
            if (counter[v[left]] == 0) 
                counter.erase(v[left]);

            left++;
        }

        max_length = max(max_length, right - left + 1);
        right++;
    }

    cout << max_length;

    return 0;
}