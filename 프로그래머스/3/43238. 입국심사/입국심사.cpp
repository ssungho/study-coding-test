#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    ll low = 1, mid, high = (ll)times.back() * n;
    
    while (low <= high) {
        mid = (low + high) / 2;
        ll cnt = 0;
        
        for (auto time : times) {
            cnt += (mid / time);
        }
        
        if (cnt >= n) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return low;
}