#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    string fizz = "Fizz";
    string buzz = "Buzz";
    string fizzbuzz = "FizzBuzz";

    for (int i = 0; i < 3; i++)
    {
        string str;
        cin >> str;

        if (str == fizz || str == buzz || str == fizzbuzz)
            continue;
        
        int num = stoi(str)  + 3 - i;

        
        if (num % 3 == 0 && num % 5 == 0)
            cout << fizzbuzz;
        else if (num % 3 == 0)
            cout << fizz;
        else if (num % 5 == 0)
            cout << buzz;
        else
            cout << num;
        
        return 0;
    }

    return 0;
}