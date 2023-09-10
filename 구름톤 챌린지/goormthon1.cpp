#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int W, R;
    cin >> W >> R;

    float OneRM = W + W * R / 30;
    
    cout << (int)floor(OneRM);

    return 0;
}