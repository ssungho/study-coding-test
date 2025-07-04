#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    int h = 0;
    while (answer < citations.size()) {
        h = citations[answer];
        if (h <= answer) break;
        answer++;
    }
    
    return answer;
}