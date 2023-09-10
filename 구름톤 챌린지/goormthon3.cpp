#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<int> v(t);

    for (int i = 0; i < t; i++)
    {
        int x, y, result;
        char oper;
        cin >> x >> oper >> y;

        if (oper == '+')
            result = x + y;
        else if (oper == '-')
            result = x - y;
        else if (oper == '*')
            result = x * y;
        else
            result = x / y;

        if (i == 0)
            v[0] = result;
        else
            v[i] = v[i - 1] + result;
    }

    cout << v.back();
    return 0;
}