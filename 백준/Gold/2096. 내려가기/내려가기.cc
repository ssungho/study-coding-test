#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

struct LINE{ 
    int left{}, center{}, right{};
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    LINE max_prev{};
    LINE min_prev{};

    for (int i = 0; i < N; i++)
    {
        LINE current{};
        cin >> current.left >> current.center >> current.right;

        LINE max_current{};
        LINE min_current{};

        max_current.left = max(max_prev.left, max_prev.center) + current.left;
        max_current.center = max(max_prev.left, max(max_prev.center, max_prev.right)) + current.center;
        max_current.right = max(max_prev.center, max_prev.right) + current.right;
        
        min_current.left = min(min_prev.left, min_prev.center) + current.left;
        min_current.center = min(min_prev.left, min(min_prev.center, min_prev.right)) + current.center;
        min_current.right = min(min_prev.center, min_prev.right) + current.right;

        memcpy(&max_prev, &max_current, sizeof(LINE));
        memcpy(&min_prev, &min_current, sizeof(LINE));
    }

    int max_score = max(max_prev.left, max(max_prev.center, max_prev.right));
    int min_score = min(min_prev.left, min(min_prev.center, min_prev.right));

    cout << max_score << " " << min_score;

    return 0;
}