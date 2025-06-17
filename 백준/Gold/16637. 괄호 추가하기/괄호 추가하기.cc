#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N{};
int max_number{-INT_MAX};
vector<int> numbers;
vector<char> operators;

int Calculate(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    return 0;
}

void Search(int index, int number)
{
    if (index == (int)numbers.size() - 1)
    {
        max_number = max(max_number, number);
        return;
    }

    Search(index + 1, Calculate(number, numbers[index + 1], operators[index]));

    if (index + 2 <= (int)numbers.size() - 1)
    {
        int left = Calculate(numbers[index + 1], numbers[index + 2], operators[index + 1]);
        int right = Calculate(number, left, operators[index]);
        Search(index + 2, right);
    }
}

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char temp;
        cin >> temp;

        if (i % 2 == 0)
            numbers.push_back(temp - '0');
        else
            operators.push_back(temp);
    }

    Search(0, numbers[0]);

    cout << max_number << '\n';

    return 0;
}