#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<string> words;
    map<char, int> counts;

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        int size = (int)word.size();
        for (int j = 0; j < size; j++)
        {
            if (counts.end() == counts.find(word[j]))
            {
                counts[word[j]] = pow(10, size - 1 - j);
            }
            else
            {
                counts[word[j]] += pow(10, size - 1 - j);
            }
        }

        words.push_back(word);
    }

    vector<pair<int, char>> frequency;
    for (auto& p : counts)
    {
        frequency.push_back({p.second, p.first});
    }

    sort(frequency.begin(), frequency.end(), greater<pair<int, char>>());
    int start = 9;
    int counts_size = (int)counts.size();
    for (int i = 0; i < counts_size; i++)
    {
        counts[frequency[i].second] = start;
        start--;
    }

    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
    {
        int number = 0;
        int size = (int)words[i].size();
        for (int j = 0; j < size; j++)
        {
            number *= 10;
            number += counts[words[i][j]];
        }
        numbers[i] = number;
    }

    int result = 0;
    for (auto i : numbers)
    {
        result += i;
    }

    cout << result;

    return 0;
}