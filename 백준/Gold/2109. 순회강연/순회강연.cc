#include <iostream>
#include <vector>
#include <queue>

using namespace std;
constexpr int max_n{10001};

int main(void)
{
    int n;
    cin >> n;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        int pay, day;
        cin >> pay >> day;
        pq.push({pay, day});
    }

    vector<int> reserved(max_n, 0);

    while (!pq.empty())
    {
        pair<int, int> lecture = pq.top();
        pq.pop();

        for (int i = lecture.second; i > 0; i--)
        {
            if (reserved[i] < lecture.first)
            {
                reserved[i] = lecture.first;
                break;
            }
        }
    }

    int total_pay = 0;
    for (int pay : reserved)
    {
        total_pay += pay;
    }

    cout << total_pay << '\n';

    return 0;
}