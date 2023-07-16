#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++)
    {
        long long num = numbers[i];

        if (num % 2 == 0)
            answer.push_back(num + 1);
        else
        {
            long long target = 1;
            while (true)
            {
                if ((num & target) == 0)
                    break;
                else
                    target *= 2;
            }
            answer.push_back(num + target / 2);
        }
    }
    return answer;
}