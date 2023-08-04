#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int memo[500][500]; // 세로, 가로
    int answer = 0;

    for(int i = 0; i < triangle[triangle.size() - 1].size(); i++)
    {
        memo[triangle.size() - 1][i] = triangle[triangle.size() - 1][i];
    }

    for (int i = triangle.size() - 1; i > -1; i--) // 세로
    {
        for (int j = 0; j < triangle[i].size(); j++) // 가로
        {
            memo[i][j] = triangle[i][j] + max(memo[i + 1][j], memo[i + 1][j + 1]);
        }
    }

    answer = memo[0][0];

    return answer;
}