#include <iostream>
using namespace std;

int memo[21][21][21];
int W(int a, int b, int c)
{   
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return W(20, 20, 20);
    if(memo[a][b][c] != 0)
        return memo[a][b][c];
    if ((a < b) && (b < c))
        return memo[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
    
    return memo[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << W(a, b, c) << '\n';
    }
    return 0;
}
