#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, string> log;
    vector<string> names;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string name;
        string state;
        cin >> name >> state;
        if(log.find(name) == log.end())
        {
            log.insert({name, state});
            names.push_back(name);
        }
        else
        {
            log[name] = state;
        }
    }
    sort(names.begin(), names.end(), greater<>());
    
    for(int i = 0; i < names.size(); i++)
    {
        string name = names[i];
        if(log[name] == "enter")
        {
            cout << name << '\n';
        }
    }

    return 0;
}