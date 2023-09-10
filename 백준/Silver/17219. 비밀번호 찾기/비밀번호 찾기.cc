#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    map<string, string> map;
    string address;
    string pw;

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> address >> pw;
        map.insert({address, pw});
    }

    for(int i = 0; i < M; i++)
    {
        cin >> address;
        if(map.find(address)!= map.end())
        {
            cout << map[address] << endl;
        }
    }

    return 0;
}