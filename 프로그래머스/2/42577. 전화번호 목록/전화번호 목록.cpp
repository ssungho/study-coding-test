#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 1; i < phone_book.size(); i++) {
        if (0 == phone_book[i].find(phone_book[i - 1])) {
            return false;
        }
    }
    
    return true;
}