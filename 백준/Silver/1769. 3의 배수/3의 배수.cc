#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string X;
    cin >> X;

    if (X.length() == 1)
    {
        if (X == "3" || X == "6" || X == "9")
        {
            cout << 0 << "\nYES";
        }
        else
        {
            cout << 0 << "\nNO";
        }
        return 0;
    }

    int count = 0;
    while (true)
    {
        int sum = 0;
        while (X.length() > 0)
        {
            sum += int(X.back() - '0');
            X.pop_back();
        }

        count++;

        if (sum < 10)
        {
            cout << count << '\n';
            if (sum % 3 == 0)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
            
            break;
        }

        X = to_string(sum);
    }

    return 0;
}