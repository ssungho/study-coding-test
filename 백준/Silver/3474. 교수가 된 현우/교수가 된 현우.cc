#include <iostream>

using namespace std;
using ll = long long;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    while (T--) 
    {
        ll N;
        cin >> N;

        int answer = 0;
        
        for (ll i = 5; i <= N; i *= 5) 
        {
            answer += N/i;
        }

        cout << answer << '\n';
    }
    
    return 0;
}