#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int max_number = 0;
    int min_number = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        
        max_number = max(max_number, temp);
        min_number = min(min_number, temp);
    }

    cout << max_number * min_number;

    return 0;
}