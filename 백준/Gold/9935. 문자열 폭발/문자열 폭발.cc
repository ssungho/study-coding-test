#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str, explode_target;
    cin >> str >> explode_target;

    int str_length = (int)str.length();
    int target_length = (int)explode_target.length();

    string result = "";
    for (int i = 0; i < str_length; i++)
    {
        result.push_back(str[i]);
        if (result.size() >= target_length)
        {
            if (result.substr(result.size() - target_length) == explode_target)
            {
                result.resize(result.size() - target_length);
            }
        }
    }

    if (result.empty())
    {
        cout << "FRULA" << '\n';
    }
    else
    {
        cout << result << '\n';
    }

    return 0;
}