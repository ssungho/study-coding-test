#include <iostream>
#include <climits>

using namespace std;

int Find(long long number, long long target, int count)
{
    if (number > target)
    {
        return INT_MAX;
    }

    if (number == target)
    {
        return count;
    }

    return min(Find(number * 2, target, count + 1), Find(number * 10 + 1, target, count + 1));
}

int main(void)
{
    int A, B;
    cin >> A >> B;

    int count = Find(A, B, 1);

    if (count == INT_MAX) count = -1;

    cout << count;

    return 0;
}