#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> stringNumbers;
    for (int number : numbers) {
        stringNumbers.emplace_back(move(to_string(number)));
    }
    
    sort(stringNumbers.begin(), stringNumbers.end(), [&](const auto& left, const auto& right) {
        return left + right > right + left;
    });
    
    for (const auto& number : stringNumbers) {
        answer += number;
    }
    
    while (answer.size() > 0 && answer[0] == '0') {
        answer = string(answer.begin() + 1, answer.end());
    }
    
    if (answer.size() == 0) {
        answer = "0";
    }
    
    return answer;
}