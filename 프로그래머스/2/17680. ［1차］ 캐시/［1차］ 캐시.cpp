#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

constexpr int hit = 1;
constexpr int miss = 5;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> caches;
    
    for (const string& city : cities) {
        
        string target = city;
        for (char& ch : target) {
            ch = toupper(ch);    
        }
        
        if (caches.size() == 0) {
            caches.push_back(target);
            answer += miss;
        }
        else {
            auto iter = find(caches.begin(), caches.end(), target);
            if (iter != caches.end()) {
                caches.erase(iter);
                caches.push_back(target);
                answer += hit;
            }
            else {
                caches.push_back(target);
                answer += miss;
            }
        }
        
        while (caches.size() > cacheSize) {
            caches.pop_front();
        }
    }
    
    return answer;
}