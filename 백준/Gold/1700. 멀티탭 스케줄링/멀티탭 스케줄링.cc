#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }

    set<int> s;
    int result = 0;

    for (int i = 0; i < k; i++) {
        auto find = s.find(v[i]);
        if (s.size() < n) {
            s.insert(v[i]);
        } else if (find == s.end()) {
            int erase = v[i];
            int index = i;
            for (auto temp : s) {
                int pos = n;
                for (int j = i; j < k; j++) {
                    if (v[j] == temp) {
                        pos = j;
                        break;
                    } 
                }
                
                if (index < pos) {
                    erase = v[pos];
                    index = pos;
                } else if (pos == n) {
                    erase = temp;
                    break;
                }
            }

            s.erase(s.find(erase));
            result++;
            s.insert(v[i]);
        }
    }
    
    cout << result << '\n';

    return 0;
}