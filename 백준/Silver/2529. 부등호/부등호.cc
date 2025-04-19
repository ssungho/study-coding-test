#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void Backtracking(vector<char>& v, vector<int>& temp, vector<bool>& visited, long long& max_number, long long& min_number) {
    if (temp.size() > v.size()) {
        long long number = 0;
        for (auto i : temp) {
            number *= 10;
            number += i;
        }
        max_number = max(max_number, number);
        min_number = min(min_number, number);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (!visited[i]) {
            char c = v[(int)temp.size() - 1];
            if ((c == '<' && temp.back() < i) || (c == '>' && temp.back() > i)) {
                visited[i] = true;
                temp.push_back(i);
                Backtracking(v, temp, visited, max_number, min_number);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(void) {
    int k;
    cin >> k;

    vector<char> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }

    vector<bool> visited(10, false);
    vector<int> temp;
    long long max_number = 0, min_number = LLONG_MAX;

    for (int i = 0; i <= 9; i++) {
        visited[i] = true;
        temp.push_back(i);
        Backtracking(v, temp, visited, max_number, min_number);
        temp.pop_back();
        visited[i] = false;
    }

    string max_string = to_string(max_number);
    string min_string = to_string(min_number);

    while ((int)max_string.length() < k + 1) {
        max_string = '0' + max_string;
    }
    while ((int)min_string.length() < k + 1) {
        min_string = '0' + min_string;
    }

    cout << max_string << '\n' << min_string;

    return 0;
}