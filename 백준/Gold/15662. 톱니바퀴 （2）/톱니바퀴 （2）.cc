#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T;

void Rotate(vector<int>& gear, int dir)
{
    if (dir == 1) 
    {
        int temp = gear[7];
        for (int i = 7; i > 0; i--)
            gear[i] = gear[i - 1];
        
        gear[0] = temp;
    }
    else 
    {
        int temp = gear[0];
        for (int i = 0; i < 7; i++)
            gear[i] = gear[i + 1];

        gear[7] = temp;
    }
}

void RotateGears(vector<vector<int>>& gears, int index, int dir, int to)
{
    if (index >= T || index < 0) return;

    int right_gear = -1;
    int left_gear = -1;
    
    if (index + 1 < T) 
        right_gear = gears[index + 1][6];
    if (index - 1 >= 0) 
        left_gear = gears[index - 1][2];

    int current_right = gears[index][2];
    int current_left = gears[index][6];

    Rotate(gears[index], dir);

    if (right_gear != -1 && right_gear != current_right && (to == 0 || to == 1)) {
        RotateGears(gears, index + 1, -dir, 1);
    }
    if (left_gear != -1 && left_gear != current_left && (to == 0 || to == -1)) {
        RotateGears(gears, index - 1, -dir, -1);
    }
}

int main(void) 
{
    cin >> T;
    vector<vector<int>> gears(T, vector<int>(8, 0));

    for (int i = 0; i < T; i++) 
    {
        string gear;
        cin >> gear;
        for (int j = 0; j < 8; j++) 
        {
            gears[i][j] = gear[j] - '0';
        }
    }

    int K;
    cin >> K;
    vector<pair<int, int>> rots(K);

    for (int i = 0; i < K; i++)
    {
        cin >> rots[i].first >> rots[i].second;
    }

    for (int i = 0; i < K; i++) 
    {
        RotateGears(gears, rots[i].first - 1, rots[i].second, 0);
    }

    int count = 0;
    for (auto& gear : gears) 
    {
        if (gear[0] == 1) 
            count ++;
    }
    cout << count << '\n';

    return 0;
}