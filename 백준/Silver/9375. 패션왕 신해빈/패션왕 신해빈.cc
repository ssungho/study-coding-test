#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        map<string, int> combinations;

        for (int i = 0; i < n; i++)
        {
            string name, kind;
            cin >> name >> kind;
            
            if (combinations.end() != combinations.find(kind))
            {
                combinations[kind]++;
            }
            else
            {
                combinations.insert({kind, 1});
            }
        }

        int comb = 1;

        for (const auto &p : combinations)
        {
            // + 안고른다.
            comb *= (p.second + 1);
        }

        // - 알몸.
        cout << comb - 1 << '\n';
    }

    return 0;
}