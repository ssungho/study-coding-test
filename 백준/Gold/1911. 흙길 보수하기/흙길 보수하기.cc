#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    int N, L;
    scanf("%d %d", &N, &L);

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) 
    {
         scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v.begin(), v.end());

    int count = 0;
    int check_point = 0;

    for (const auto& p : v)
    {
        if (check_point < p.second) {
            check_point = max(p.first, check_point);
            int distance = p.second - check_point;
            int val = (distance / L);
            if ((distance % L) > 0) 
                val++;

            count += val;
            check_point += val * L;
        }
    }

    printf("%d", count);

    return 0;
}