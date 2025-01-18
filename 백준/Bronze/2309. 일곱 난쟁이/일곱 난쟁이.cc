#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int n = 9;
    vector<int> heights(9, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    // 7명의 합이 100;
    // 두명을 선택하고 제외한 나머지의 합이 100이 되면 되는거 아닌가.

    int total_height = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j)
                {
                    total_height += heights[k];
                }
            }

            if (total_height == 100)
            {
                vector<int> selected;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                    {
                        selected.push_back(heights[k]);
                    }
                }

                sort(selected.begin(), selected.end(), [](int a, int b) -> bool
                     { return a < b; });

                for (int height : selected)
                {
                    cout << height << endl;
                }
                return 0;

            }
            else
                total_height = 0;
        }
    }

    return 0;
}