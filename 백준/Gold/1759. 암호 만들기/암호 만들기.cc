#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector<char> v;
vector<bool> visited;

bool isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void Backtracking(int index, vector<char> &vec)
{
    if (vec.size() == L)
    {
        string code;
        int vowels = 0;
        int consonants = 0;

        for (auto ch : vec)
        {
            code += ch;

            if (isVowel(ch))
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }

        if (vowels >= 1 && consonants >= 2)
            cout << code << '\n';

        return;
    }

    for (int i = index; i < C; i++)
    {
        if (visited[i] == true)
            continue;

        visited[i] = true;
        vec.push_back(v[i]);

        Backtracking(i + 1, vec);

        visited[i] = false;
        vec.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    cin >> L >> C;

    v.resize(C);
    visited.resize(C);

    for (int i = 0; i < C; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<char> temp;
    Backtracking(0, temp);

    return 0;
}