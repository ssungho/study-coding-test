#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> TiPi_array; // 상담 기간과 얻는 돈을 pair로 저장한 배열

int main(void)
{
    int n;
    cin >> n;

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int *memo = new int[n + 1]; // memo[n]은 n일 이후부터 얻는 최대 수익
    for(int i = 0; i < n + 1; i++)
    {
        memo[i] = 0;
    }
    // Ti, Pi 배열을 초기화
    TiPi_array.push_back({0,0});
    for(int i = 0; i < n; i++)
    {
        int t,p;
        cin >> t >> p;
        TiPi_array.push_back({t,p});
    } 

    int day; // 상담에 필요한 기간
    int pay; // 상담시 얻는 돈
    int max_pay = 0;

    for(int i = 1; i < n + 1; i++)
    {
        day = TiPi_array[i].first - 1;
        pay = TiPi_array[i].second;

        if(i + day < n + 1)
        {
            memo[i + day] = max(max_pay + pay, memo[i + day]);
        }
        
        max_pay = max(memo[i], max_pay);
    }
    cout << max_pay;
    return 0;
}