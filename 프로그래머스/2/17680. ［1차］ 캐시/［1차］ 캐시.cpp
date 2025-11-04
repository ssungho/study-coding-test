#include <string>
#include <vector>
#include <deque>

using namespace std;

constexpr int hit = 1;
constexpr int miss = 5;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> caches;
    
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
            int size = caches.size();
            int pos = -1;
            for (int i = 0; i < size; i++) {
                if (caches[i] == target) {
                    pos = i;
                    break;
                }
            }
            
            if (pos != -1) {
                for(int i = pos; i < size - 1; i++) {
                    caches[i] = caches[i + 1];
                }
                caches.pop_back();
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