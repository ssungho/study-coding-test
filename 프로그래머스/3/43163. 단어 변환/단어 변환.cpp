#include <string>
#include <vector>
#include <climits>
#include <map>
using namespace std;

int min_count = INT_MAX;
map<string, int> visited;

void dfs(vector<string>& words, string current, string& target, int count)
{
    if (count >= (int)words.size())
        return;
    
    if (current == target)
    {
        min_count = min(count, min_count);
        return;
    }
    
    int word_count = (int)words.size();
    for (int i = 0; i < word_count; i++)
    {
        string& selected = words[i];
        if (visited[selected] != 0)
        {
            continue;
        }
        
        int length = selected.length();
        int miss_count = 0;
        for (int j = 0; j < length; j++)
        {
            if (current[j] != selected[j])
            {
                miss_count++;
            }
        }
        
        if (miss_count == 1)
        {
            visited[selected] = 1;
            dfs(words, selected, target, count + 1);
            visited[selected] = 0;
        }
    }
        
}

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    
    for (string& word : words)
    {
        visited.insert({word, 0});
    }
    
    dfs(words, begin, target, 0);
    
    if (min_count != INT_MAX)
        answer = min_count;
   
    return answer;
}
