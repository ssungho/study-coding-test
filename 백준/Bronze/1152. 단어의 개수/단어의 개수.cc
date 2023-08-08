#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string temp;
    int cnt = 0;
    
    while(cin >> temp)
        cnt++;
    
    cout << cnt;
    return 0;
}