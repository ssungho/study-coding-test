#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int last_time = 24 * 60 - 1;

vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<int> answer;
    map<int, int> m;
    map<int, int> save;
    
    for (string& record : records)
    {
        string time = record.substr(0, 5);
        string number = record.substr(6, 4);
        string type = record.substr(11);
        
        int number_int = stoi(number);
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        int total = hour * 60 + min;
        
        if (type == "IN") 
        {
            m.insert({number_int, total});
        }
        else 
        {
            auto iter = m.find(number_int);
            int fee = (total - (*iter).second);
            
            if (save.find(number_int) != save.end())
            {
                save[number_int] += fee;
            }
            else
            {
                save.insert({number_int, fee});
            }
            
            iter = m.erase(iter);
        }
    }
    
    for (auto& p : m)
    {
        if (save.find(p.first) != save.end())
        {
            save[p.first] += last_time - p.second;
        }
        else
        {
            save.insert({p.first, last_time - p.second});
        }
    }
    
    vector<pair<int, int>> temp(save.begin(), save.end());
    sort(temp.begin(), temp.end());
    for (auto& p : temp)
    {
        int total_time = p.second;
        int default_time = fees[0];
        int default_fee = fees[1];
        int unit_time = fees[2];
        int unit_fee = fees[3];
        
        if (total_time <= default_time) 
        {
            answer.push_back(default_fee);
            continue;
        }
        
        int total_fee = default_fee;
        total_time -= default_time;
        total_fee += (total_time / unit_time * unit_fee);
        
        if (total_time % unit_time) 
        {
            total_fee += unit_fee;
        }
        
        answer.push_back(total_fee);
    }
    
    return answer;
}