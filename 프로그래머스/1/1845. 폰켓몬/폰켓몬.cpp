#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    sort(nums.begin(), nums.end());
    
    int cnt = 1;
    int temp = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == temp) continue;
        temp = nums[i];
        cnt++;
    }

    answer = cnt > nums.size() / 2 ? nums.size() / 2 : cnt;
    
    return answer;
}