#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() -1;
    
    while (left < right) 
    {
        int sum = people[left] + people[right];
        
        if (sum > limit) 
        {
            right--;
            answer++;
        }
        else 
        {
            left++;
            right--;
            answer++;
        }
    }
    
    if (left == right) 
        answer++;
    
    return answer;
}