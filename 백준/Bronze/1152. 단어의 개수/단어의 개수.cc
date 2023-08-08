#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string temp;
    int cnt = 0;
    while(cin >> temp)
        cnt++;
    
    cout << cnt;
    return 0;
}