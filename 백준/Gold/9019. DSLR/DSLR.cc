#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {

    int T;
    cin >> T;
    
    while (T-- > 0) {

        int A, B;
        cin >> A >> B;

        bool visited[10000]{};
       
        queue<pair<int, string>> q;

        q.push({A, ""});
        visited[A] = true;

        string total_command = "";

        while(true) {
            int num = q.front().first;
            string command = q.front().second;
            q.pop();

            if (num == B) {
                total_command = command;
                break;
            }

            int front = num / 1000;
            int back = num % 10;

            int D = num * 2 % 10000;
            int S = (num + 9999) % 10000;
            int L = num * 10 % 10000 + front;
            int R = num / 10 + back * 1000;

            if (!visited[D]) {
                q.push({D, command + 'D'});
                visited[D] = true;
            }

            if (!visited[S]) {
                q.push({S, command + 'S'});
                visited[S] = true;
            }

            if (!visited[L]) {
                q.push({L, command + 'L'});
                visited[L] = true;
            }

            if (!visited[R]) {
                q.push({R, command + 'R'});
                visited[R] = true;
            }
        }

        cout << total_command << '\n';
    }

    return 0;
}