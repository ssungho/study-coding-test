#include <string>
#include <vector>
#include <memory.h>

using namespace std;

long long memo[100001];
int solution(int n) {
    
    memset(&memo, 0, 100001 * sizeof(long long));
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    
    for (int i = 3; i <= n; ++i) {
        memo[i] = (memo[i - 1] + memo[i - 2]) % 1234567;
    }
    
    return memo[n];
}