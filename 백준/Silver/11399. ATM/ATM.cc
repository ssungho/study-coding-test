#include <iostream>
#include <vector>
using namespace std;
// 삽입정렬 연습용

int main(void)
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 1; i < n; i++)
    {
        int index = i;
        int select = v[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[j] < v[i])
            {
                index = j + 1;
                break;
            }

            if (j == 0)
                index = 0;
        }
        for (int j = i; j > index; j--)
            v[j] = v[j - 1];

        v[index] = select;
    }

    vector<int> s(n);
    s[0] = v[0];
    for (int i = 1; i < n; i++)
        s[i] = v[i] + s[i - 1];

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += s[i];

    cout << sum;

    return 0;
}