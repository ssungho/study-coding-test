#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    map<string, int> m;
    string num = "";
    
    for (char ch : s) {
        if ('0' <= ch && ch <= '9') {
            num += ch;
        }
        else if (num.size()) {
            m[num]++;
            num = "";
        }
    }
    
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](auto& l, auto& r){
        return l.second > r.second;
    });
    
    
    vector<int> answer(v.size());
    for (int i = 0; i < v.size(); i++) {
        answer[i] = stoi(v[i].first);
    }
    
    return answer;
}