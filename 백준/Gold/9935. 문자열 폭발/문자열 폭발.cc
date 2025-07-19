#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str, explode;
    cin >> str >> explode;

    size_t str_size = str.size();
    size_t ex_size = explode.size();
    string result = "";
    result.reserve(str_size);

    for (size_t i = 0; i < str_size; i++) {
        result.push_back(str[i]);
        if (result.size() >= ex_size) {
            bool matched = true;
            for (int j = 0; j < ex_size; j++) {
                if (result[result.size() - ex_size + j] != explode[j]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                for (int j = 0; j < ex_size; j++) {
                    result.pop_back();
                }
            }
        }
    }

    cout << (result.size() ? result : "FRULA") << '\n';

    return 0;
}