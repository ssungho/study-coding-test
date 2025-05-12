#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    if (n == 0 || n == 1)
    {
        cout << n;
        return 0;
    }

    vector<string> dp(n + 1);
    dp[0] = '0';
    dp[1] = '1';

    for (int i = 2; i <= n; i++)
    {
        string sum = "";
        string num1 = dp[i - 1];
        string num2 = dp[i - 2];

        int size1 = (int)num1.size();
        int size2 = (int)num2.size();
        int min_size = min(size1, size2);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int temp = 0;
        for (int i = 0; i < min_size; i++)
        {
            int number = (num1[i] - '0') + (num2[i] - '0') + temp;
            temp = number / 10;
            if (temp)
                number %= 10;

            sum += (number + '0');
        }

        if (size1 > size2)
        {
            for (int i = min_size; i < size1; i++)
            {
                int number = (num1[i] - '0') + temp;
                temp = number / 10;
                if (temp)
                    number %= 10;

                sum += (number + '0');
            }
            if (temp == 1)
                sum += '1';
        }
        else
        {
            for (int i = min_size; i < size2; i++)
            {
                int number = (num2[i] - '0') + temp;
                temp = number / 10;
                if (temp)
                    number %= 10;

                sum += (number + '0');
            }
            if (temp == 1)
                sum += '1';
        }

        reverse(sum.begin(), sum.end());

        dp[i] = sum;
    }

    cout << dp[n];

    return 0;
}