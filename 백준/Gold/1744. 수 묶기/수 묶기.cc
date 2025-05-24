#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solution(vector<int> &numbers, int size, int &sum)
{
    for (int i = 1; i < size; i++)
    {
        int mul = numbers[i] * numbers[i - 1];
        int add = numbers[i] + numbers[i - 1];

        if (add < mul)
        {
            sum -= add;
            sum += mul;
            i++;
        }
    }
}

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

    Solution(positive_numbers, num_positives, sum);
    Solution(negative_numbers, num_negatives, sum);

    cout << sum;

    return 0;
}