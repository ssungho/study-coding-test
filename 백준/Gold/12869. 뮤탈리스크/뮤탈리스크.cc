#include <iostream>
#include <climits>
#include <memory.h>

using namespace std;
constexpr int max_n{3};
constexpr int damage[6][max_n] {
    { 9, 3, 1 },
    { 9, 1, 3 },
    { 1, 3, 9 },
    { 1, 9, 3 },
    { 3, 9, 1 },
    { 3, 1, 9 },
} ;

int dp[61][61][61] {};
int n;

int dfs(int hp1, int hp2, int hp3) {
    hp1 = max(hp1, 0);
    hp2 = max(hp2, 0);
    hp3 = max(hp3, 0);

    if (hp1 == 0 && hp2 == 0 && hp3 == 0) {
        return 0;
    }

    if (dp[hp1][hp2][hp3] != -1) {
        return dp[hp1][hp2][hp3];
    }

    int& count = dp[hp1][hp2][hp3];
    count = INT_MAX;

    for (int i = 0; i < 6; i++) {
        count = min(count, dfs(hp1 - damage[i][0], hp2 - damage[i][1], hp3 - damage[i][2]) + 1);
    }

    return count;
}

int main(void) {
    cin >> n;
   
    int hps[max_n] {};
    for (int i = 0; i < n; i++) {
        cin >> hps[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(hps[0], hps[1], hps[2]) << '\n';

    return 0;
}