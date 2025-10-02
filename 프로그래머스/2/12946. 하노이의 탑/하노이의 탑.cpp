#include <string>
#include <vector>

using namespace std;

void move(vector<vector<int>>& v, int from, int temp, int to, int n) {
    if (n == 0)
        return;
    move(v, from, to, temp, n - 1);
    v.push_back({from, to});
    move(v, temp, from, to, n - 1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    move(answer, 1, 2, 3, n);
    return answer;
}