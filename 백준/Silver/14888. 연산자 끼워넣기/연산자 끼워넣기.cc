#include <iostream>
#include <climits>

using namespace std;

int N = 0;
int nums[100]{};
int opers[4]{};
int max_result = INT_MIN;
int min_result = INT_MAX;

int Calculate(int a, int b, int oper)
{
    if (oper == 0)
        return a + b;
    else if (oper == 1)
        return a - b;
    else if (oper == 2)
        return a * b;
    else
        return a / b;
}

void Backtracking(int index, int result)
{
    if (index == N)
    {
        min_result = min(min_result, result);
        max_result = max(max_result, result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (opers[i] <= 0)
            continue;

        opers[i]--;

        Backtracking(index + 1, Calculate(result, nums[index], i));
        
        opers[i]++;
    }
}

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> opers[i];
    }

    Backtracking(1, nums[0]);

    cout << max_result << '\n';
    cout << min_result;

    return 0;
}