#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string Convert(int n, int k)
{
    string str = "";
    while (n > 0) 
    {
        int mod = n % k;
        str += to_string(mod);
        n /= k;
    }
    
    reverse(str.begin(), str.end());
    return str;
}

bool IsPrime(long long num)
{
    if (num < 2) return false;
    
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) 
{
    int answer = 0;
    
    string target = Convert(n, k);
    
    vector<string> strings;
    
    string temp = "";
    for (int i = 0; i < target.size(); i++)
    {
        if (target[i] != '0')
        {
            temp += target[i];
        }
        else
        {
            if (temp != "")
                strings.push_back(temp);
            temp = "";
        }
    }
    
    if (temp != "") strings.push_back(temp);
    
    for (const string& str : strings)
    {
        long long num = stoll(str);
        
        if (IsPrime(num))
            answer++;
    }
    
    return answer;
}