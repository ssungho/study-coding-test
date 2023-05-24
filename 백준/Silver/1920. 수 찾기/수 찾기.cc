#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, m;

    cin >> n;

    vector<long> vn;
    for (int i = 0; i < n; i++)
    {
        long temp;
        cin >> temp;
        vn.push_back(temp);
    }

    sort(vn.begin(), vn.end());

    cin >> m;

    vector<long> vm;
    for (int i = 0; i < m; i++)
    {
        long temp;
        cin >> temp;
        vm.push_back(temp);
    }

    for (int i = 0; i < vm.size(); i++)
    {
        bool have = binary_search(vn.begin(), vn.end(), vm[i]);

        cout << have << '\n';
    }

    return 0;
}
