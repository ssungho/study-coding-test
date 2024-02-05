#include <iostream>
#include <algorithm>

using namespace std;

int graph[100][100];

int main(void)
{
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int val;
            cin >> val;

            if(val == 0)
                graph[i][j] = 9999;
            else
                graph[i][j] = 1;
        }
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for(int k = 0; k < size; k++)
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(graph[i][j] == 9999)
                cout << "0 ";
            else
                cout << "1 ";
        }
        cout << '\n';
    }

    return 0;
}