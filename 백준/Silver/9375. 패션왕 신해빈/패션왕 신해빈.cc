#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        map<string, int> map;
        vector<string> kinds;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            string name, kind;
            cin >> name >> kind;
            if (map.find(kind) == map.end())
            {
                map.insert({kind, 1});
                kinds.push_back(kind);
            }
            else
            {
                map[kind]++;
            }
        }
        int sum = 1;
        for (int i = 0; i < kinds.size(); i++)
        {
            sum *= (map[kinds[i]] + 1);
        }
        cout << sum - 1 << '\n';
    }

    return 0;
}