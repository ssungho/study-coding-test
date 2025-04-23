#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<int> pack(M);
    vector<int> single(M);

    for (int i = 0; i < M; i++)
    {
        cin >> pack[i];
        cin >> single[i];
    }

    int min_pack = *min_element(pack.begin(), pack.end());
    int min_single = *min_element(single.begin(), single.end());

    if (min_pack > min_single * 6)
        min_pack = min_single * 6;

    int total = min_pack * (N / 6);

    N %= 6;
    min_single *= N;

    if (min_pack < min_single)
        total += min_pack;
    else
        total += min_single;
    
    cout << total;

    return 0;
}