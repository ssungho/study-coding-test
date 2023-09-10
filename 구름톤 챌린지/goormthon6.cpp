#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct arr
{
    string first;
    string second;
    string third;
};

int main()
{
    int n;
    cin >> n;
    set<string> s; // 정렬 + 중복제거
    vector<arr> v; // 집합 벡터
    string str;
    cin >> str;

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            string substr1 = str.substr(0, i);
            string substr2 = str.substr(i, j - i);
            string substr3 = str.substr(j, n - j);

            s.insert(substr1);
            s.insert(substr2);
            s.insert(substr3);

            v.push_back({substr1, substr2, substr3});
        }
    }
    vector<string> str_to_v(s.begin(), s.end());

    int max_point = 0;
    for (int i = 0; i < v.size(); i++)
    {

        int sum_point = (find(str_to_v.begin(), str_to_v.end(), v[i].first) - str_to_v.begin() + 1 + find(str_to_v.begin(), str_to_v.end(), v[i].second) - str_to_v.begin() + 1 + find(str_to_v.begin(), str_to_v.end(), v[i].third) - str_to_v.begin() + 1);

        if (max_point < sum_point)
            max_point = sum_point;
    }

    cout << max_point;
    return 0;
}