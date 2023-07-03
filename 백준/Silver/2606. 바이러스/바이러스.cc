#include <iostream>
#include <vector>
using namespace std;

vector<int> computers[101];
bool infected[101];
int cnt = -1;

void DFS(int computer_number)
{
    infected[computer_number] = true;
    cnt++;

    for(int i = 0; i < computers[computer_number].size(); i++)
        if(!infected[computers[computer_number][i]])
            DFS(computers[computer_number][i]);
}

int main(void)
{
    int computer_number, edge;
    cin >> computer_number >> edge;

    int num1, num2;
    for(int i = 0; i < edge; i++)
    {
        cin >> num1 >> num2;
        computers[num1].push_back(num2);
        computers[num2].push_back(num1);
    }
    DFS(1);
    cout << cnt;
    return 0;
}