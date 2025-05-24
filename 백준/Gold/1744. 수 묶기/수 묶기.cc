#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> positive_numbers;
    vector<int> negative_numbers;
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        int number;
        cin >> number;

        if (number > 0)
        {
            positive_numbers.push_back(number);
        }
        else
        {
            negative_numbers.push_back(number);
        }

        sum += number;
    }

    sort(positive_numbers.begin(), positive_numbers.end(), greater<int>());
    sort(negative_numbers.begin(), negative_numbers.end());

    int num_positives = (int)positive_numbers.size();
    int num_negatives = (int)negative_numbers.size();

    int prev = 0;

    for (int i = 1; i < num_positives; i++)
    {
        int mul = positive_numbers[i] * positive_numbers[i - 1];
        int add = positive_numbers[i] + positive_numbers[i - 1];

        if (add < mul)
        {
            sum -= add;
            sum += mul;
            i++;
        }
    }

    for (int i = 1; i < num_negatives; i++)
    {
        int mul = negative_numbers[i] * negative_numbers[i - 1];
        int add = negative_numbers[i] + negative_numbers[i - 1];

        if (add < mul)
        {
            sum -= add;
            sum += mul;
            i++;
        }
    }

    cout << sum;

    return 0;
}