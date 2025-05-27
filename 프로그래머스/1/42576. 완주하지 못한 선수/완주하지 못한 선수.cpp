#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std; 

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
   
    map<string, int> infos;
    for (auto& name : participant)
    {
        if (infos.find(name) == infos.end())
        {
            infos.insert({name, 1});
        }
        else
        {
            infos[name]++;
        }
    }  
    
    for (auto& name : completion)
    {
        infos[name]--;
    }
    
    for (auto& info : infos)
    {
        if (info.second > 0)
        {
            answer = info.first;
            break;
        }
    }
 
    return answer;
}