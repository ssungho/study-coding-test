#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int answer = 0;

    int max_w = 0;
    int max_h = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        std::sort(sizes[i].begin(), sizes[i].end());

        if (sizes[i][0] > max_w)
            max_w = sizes[i][0];

        if (sizes[i][1] > max_h)
            max_h = sizes[i][1];
    }

    answer = max_w * max_h;

    return answer;
}