#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> v(K);
    for (int i = 0; i < K; i++)
    {
        cin >> v[i];
    }

    int count = 0;
    set<int> s;
    for (int i = 0; i < K; i++)
    {
        auto find_iter = s.find(v[i]);
        if (s.size() == N)
        {
            if (find_iter == s.end())
            {
                int last_at = -1;
                for (auto iter = s.begin(); iter != s.end();)
                {
                    int at = -1;
                    for (int start = i + 1; start < K; start++)
                    {
                        if (*iter == v[start])
                        {
                            at = start;
                            last_at = max(at, last_at);
                            break;
                        }
                    }

                    if (at == -1)
                    {
                        count++;
                        s.erase(iter);
                        last_at = -1;
                        break;
                    }
                    else
                    {
                        iter++;
                    }
                }

                if (last_at != -1)
                {
                    count++;
                    s.erase(v[last_at]);
                }

                s.insert(v[i]);
            }
        }
        else
        {
            if (find_iter == s.end())
            {
                s.insert(v[i]);
            }
        }
    }

    cout << count << '\n';

    return 0;
}