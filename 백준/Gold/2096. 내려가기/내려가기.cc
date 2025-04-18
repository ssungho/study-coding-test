#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct LINE{ 
    int left{}, center{}, right{};
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<LINE> v(N, {0, 0, 0});

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].left >> v[i].center >> v[i].right;
    }

    queue<LINE> max_q;
    queue<LINE> min_q;

    max_q.push({0, 0, 0});
    min_q.push({0, 0, 0});

    for (int i = 1; i <= N; i++)
    {
        LINE max_prev = max_q.front();
        LINE min_prev = min_q.front();

        max_q.pop();
        min_q.pop();

        LINE max_current {};
        LINE min_current {};

        max_current.left = max(max_prev.left, max_prev.center) + v[i - 1].left;
        max_current.center = max(max_prev.left, max(max_prev.center, max_prev.right)) + v[i - 1].center;
        max_current.right = max(max_prev.center, max_prev.right) + v[i - 1].right;
        
        min_current.left = min(min_prev.left, min_prev.center) + v[i - 1].left;
        min_current.center = min(min_prev.left, min(min_prev.center, min_prev.right)) + v[i - 1].center;
        min_current.right = min(min_prev.center, min_prev.right) + v[i - 1].right;

        max_q.push(max_current);
        min_q.push(min_current);
    }

    int max_score = max(max_q.front().left, max(max_q.front().center, max_q.front().right));
    int min_score = min(min_q.front().left, min(min_q.front().center, min_q.front().right));

    cout << max_score << " " << min_score;

    return 0;
}