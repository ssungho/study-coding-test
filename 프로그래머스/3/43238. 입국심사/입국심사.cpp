#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long maxTime = (long long)times[times.size() - 1] * n;
    long long minTime = 1;
    
    while (minTime < maxTime) {
        long long middle = (maxTime + minTime) / 2;
        long long sum = 0;

        for (long long time : times) {
            sum += middle / time;
        }
        
        if (sum >= n) {
            maxTime = middle;
        } 
        else {
            minTime = middle + 1;
        }
    }
    
    answer = maxTime;
    
    return maxTime;
}