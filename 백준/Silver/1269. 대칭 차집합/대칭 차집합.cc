#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;

    vector<int> list1;
    vector<int> list2;

    cin >> n >> m;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        list1.push_back(num);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        list2.push_back(num);
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    vector<int> difference_list1(n + m);
    auto iter = set_difference(list1.begin(), list1.end(), list2.begin(), list2.end(), difference_list1.begin());
    difference_list1.erase(iter, difference_list1.end());

    vector<int> difference_list2(n + m);
    iter = set_difference(list2.begin(), list2.end(), list1.begin(), list1.end(), difference_list2.begin());
    difference_list2.erase(iter, difference_list2.end());

    cout << difference_list1.size() + difference_list2.size();

    return 0;
}