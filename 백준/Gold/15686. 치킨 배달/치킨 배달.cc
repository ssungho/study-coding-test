#include <iostream>
#include <vector>
#include <climits>

using namespace std;

constexpr int max_n{50};
constexpr int max_index{max_n + 1};
int map[max_index][max_index] {};

vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<int> temp;

int n, m;
int min_distance { INT_MAX };

int GetDistance() {
    int sum_distance = 0;
    for (auto p : houses) {
        int temp_distance = INT_MAX;
        for (int i : temp) {
            int current_distance = abs(p.first - chickens[i].first) + 
                                   abs(p.second - chickens[i].second);
            temp_distance = min(temp_distance, current_distance);
        }
        sum_distance += temp_distance;
    }
    return sum_distance;
}

void Backtracking(int index, int count) {
    if (count == m) {
        min_distance = min(min_distance, GetDistance());
        return;
    }

    for (int i = index; i < (int)chickens.size(); i++) {
        int y = chickens[i].first;
        int x = chickens[i].second;

        temp.push_back(i);
        Backtracking(i + 1, count + 1);
        temp.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            if (map[i][j] == 1)
                houses.push_back({i, j});
            else if (map[i][j] == 2)
                chickens.push_back({i, j});
        }
    }

    Backtracking(0, 0);
    cout << min_distance << '\n';

    return 0;
}