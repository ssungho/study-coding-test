#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (const auto& command : commands) {
        vector<int> splitArray(array.begin() + (command[0] - 1), array.begin() + command[1]);
        sort(splitArray.begin(), splitArray.end());
        answer.push_back(splitArray[command[2] - 1]);
    }
    return answer;
}