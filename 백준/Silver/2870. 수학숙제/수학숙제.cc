#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsNumber(char ch)
{
    return ('0' <= ch && ch <= '9');
}

int main(void)
{
    int N;
    cin >> N;
    vector<string> numbers;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        int str_size = (int)str.size();
        for (int j = 0; j < str_size; j++)
        {
            if (IsNumber(str[j]))
            {
                string str_num(1, str[j]);
                for (int k = j + 1; k < str_size; k++)
                {
                    j = k;
                    if (IsNumber(str[k]))
                        str_num += str[k];
                    else 
                        break;
                }

                while (str_num.size() > 1 && str_num.front() == '0')
                {
                    str_num = str_num.substr(1);
                }

                numbers.push_back(str_num);
            }
        }
    }

    sort(numbers.begin(), numbers.end(),
         [&](auto &left, auto &right) -> bool
         {
             if (left.size() == right.size())
                 return left < right;
             return left.size() < right.size();
         });

    for (string &number : numbers)
    {
        cout << number << '\n';
    }

    return 0;
}