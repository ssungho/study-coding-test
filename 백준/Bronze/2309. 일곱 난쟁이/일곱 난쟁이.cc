#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 9;
    vector<int> heights(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    int total_height = 0;
    for (int height : heights)
    {
        total_height += height;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (total_height - (heights[i] + heights[j]) == 100)
            {
                vector<int> selected;
                for (int k = 0; k < n; ++k)
                {
                    if (k != i && k != j)
                    {
                        selected.push_back(heights[k]);
                    }
                }

                sort(selected.begin(), selected.end());

                for (int height : selected)
                {
                    cout << height << endl;
                }
                return 0;
            }
        }
    }

    return 0;
}
