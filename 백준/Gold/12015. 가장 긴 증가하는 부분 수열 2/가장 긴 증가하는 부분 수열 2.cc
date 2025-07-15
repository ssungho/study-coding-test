#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> lis;

int BinarySearch(int value)
{
    if (lis.empty()) return 0;

    int result = (int)lis.size();
    int left_index = 0;
    int right_index = result - 1;

    while (left_index <= right_index)
    {
        int mid = (left_index + right_index) / 2;

        if (lis[mid] >= value)
        {
            result = mid;
            right_index = mid - 1;
        }
        else
        {
            left_index = mid + 1;
        }
    }

    return result;
}

int main(void)
{
    cin >> n;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (lis.empty() || lis.back() < a[i])
        {
            lis.push_back(a[i]);
        }
        else
        {
            int size = (int)lis.size();
            int index = BinarySearch(a[i]);
            lis[index] = a[i];
        }
    }

    cout << lis.size() << '\n';

    return 0;
}