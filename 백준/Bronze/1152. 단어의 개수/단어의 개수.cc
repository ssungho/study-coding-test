#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string temp;
    getline(cin, temp);
    int cnt = 0;
    if (temp == " ")
    {
        cout << cnt;
    }
    else
    {
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == ' ')
            {
                if (i != 0)
                    cnt++;
            }
            if (i == temp.size() - 1 && temp[i] != ' ')
                cnt++;
        }
        cout << cnt;
    }

    return 0;
}