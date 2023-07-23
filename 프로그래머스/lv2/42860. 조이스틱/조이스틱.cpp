#include <string>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int name_length = name.size();

    for (int i = 0; i < name_length; i++)
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    

    int count = name_length - 1;
    int next;
    for (int i = 0; i < name_length; i++)
    {
        next = i + 1;
        while (next < name_length && name[next] == 'A')
            next++;
        
        count = min(count, i + (name_length - next) + min(i, name_length - next));
    }
    answer += count;
    return answer;
}