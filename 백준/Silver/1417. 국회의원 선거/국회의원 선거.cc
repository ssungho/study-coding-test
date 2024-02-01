#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin >>n;
    
    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int vote;
        cin >> vote;
        v.push_back(vote);
    }

    int cnt = 0;
    while(true)
    {
        int max_vote = *max_element(v.begin() + 1, v.end());
        if(v[0] > max_vote)
            break;

        v[max_element(v.begin() + 1, v.end()) - v.begin()]--;
        v[0]++;
        cnt++;
    }

    cout << cnt;    

    return 0;
}