#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> v(26, 0);

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        int size = (int)word.size();
        int num = 1;
        for (int j = size - 1; j >= 0; j--)
        {
            v[word[j] - 'A'] += num;
            num *= 10;
        }
    }

    sort(v.begin(), v.end(), greater<int>());

    int weight = 9;
    int result = 0;
    
    for (auto i : v)
    {
        if (i == 0)
            continue;

        result += (weight * i);
        weight--;
    }

    cout << result;

    return 0;
}