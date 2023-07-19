#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        long long stock;
        vector<long long> stocks;

        int N;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> stock;
            stocks.push_back(stock);
        }

        long long sum_profit = 0;
        long long max_stock = -1;

        for (int j = N - 1; j >= 0; j--)
        {
            long long curr_stock = stocks[j];

            if (curr_stock >= max_stock)
                max_stock = curr_stock;
            else
                sum_profit += (max_stock - curr_stock);
        }
        cout << sum_profit << '\n';
    }

    return 0;
}