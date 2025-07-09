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
                string str_num = "";

                while (IsNumber(str[j]))
                {
                    str_num += str[j];
                    j++;
                }

                while (str_num.size() > 1 && str_num.front() == '0')
                {
                    str_num.erase(str_num.begin());
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