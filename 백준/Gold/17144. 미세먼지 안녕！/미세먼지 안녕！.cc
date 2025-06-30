#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

constexpr int dir_size{4};
constexpr int dy[dir_size]{-1, 1, 0, 0};
constexpr int dx[dir_size]{0, 0, -1, 1};
constexpr int max_size{50};

int area[max_size + 1][max_size + 1] {};
int area_copy[max_size + 1][max_size + 1] {};

void CopyArea() {
    for (int i = 0; i < max_size + 1; i++) {
        memcpy(area[i], area_copy[i], sizeof(int) * (max_size + 1));
    }
}

void ClearCopy() {
    for (int i = 0; i < max_size + 1; i++)
        memset(area_copy[i], 0,  sizeof(int) * (max_size + 1));
}

int main(void)  {
    int R, C, T;
    cin >> R >> C >> T;
    vector<vector<int>> air_cleaner;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> area[i][j];
            if (area[i][j] == -1) {
                air_cleaner.push_back({i, j});
            }
        }
    }

    for (int t = 0; t < T; t++) {
        ClearCopy();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (area[i][j] > 0) {
                    int count = 0;
                    int amount = (float)area[i][j] / 5.0f;

                    for (int dir = 0; dir < dir_size; dir++) {
                        int ny = dy[dir] + i;
                        int nx = dx[dir] + j;
                        if (0 <= ny && ny < R && 0 <= nx && nx < C && area[ny][nx] != -1) {
                            count++;
                            area_copy[ny][nx] += amount;
                        }
                    }
                    area_copy[i][j] += area[i][j] - amount * count;
                }
                else if (area[i][j] == -1) {
                    area_copy[i][j] = -1;
                }
            }
        }

        int upper = air_cleaner[0][0];
        for (int i = upper - 1; i > 0; i--)
            area_copy[i][0] = area_copy[i - 1][0];
        for (int i = 0; i < C - 1; i++)
            area_copy[0][i] = area_copy[0][i + 1];        
        for (int i = 0 ; i < upper; i++)
            area_copy[i][C - 1] = area_copy[i + 1][C - 1];
        for (int i = C - 1; i > 1; i--)
            area_copy[upper][i] = area_copy[upper][i - 1];
        
        area_copy[upper][0] = -1;
        area_copy[upper][1] = 0;

        int lower = air_cleaner[1][0];
        for (int i = lower + 1; i < R - 1; i++)
            area_copy[i][0] = area_copy[i + 1][0];
        for (int i = 0; i < C - 1; i++)
            area_copy[R - 1][i] = area_copy[R - 1][i + 1];        
        for (int i = R - 1; i > lower; i--)
            area_copy[i][C - 1] = area_copy[i - 1][C - 1];
        for (int i = C - 1; i > 1; i--)
            area_copy[lower][i] = area_copy[lower][i - 1];

        area_copy[lower][0] = -1;
        area_copy[lower][1] = 0;

        CopyArea();
    }

    int count = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (area[i][j] > 0)
                count += area[i][j];
        }
    }
    cout << count << '\n';

    return 0;
}