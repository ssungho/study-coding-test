#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    int n;
    cin >> n;
    
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int target = arr[i];
        int left = 0;
        int right = n - 1;

        while (true) 
        {
            if (left >= right)
            {
                break;
            }

            int sum = arr[left] + arr[right];

            if (sum > target) 
            {
                --right;
            }
            else if (sum < target)
            {
                ++left;
            }
            else 
            {
                if (left == i) 
                {
                    ++left;
                    continue;
                }
                
                if (right == i) 
                {
                    --right;
                    continue;
                }

                ++result;
                break;
            }
        }
    }

    cout << result << '\n';

    return 0;
}