#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) 
{
    int answer = 0;
    int playerCount = 24;
    
    vector<int> servers(playerCount, 0);
    for (int i = 0; i < playerCount; i++) 
    {
        int Range = m + servers[i] * m;
        if (players[i] >= Range) 
        {
            int addServer = players[i] / m - servers[i];
            servers[i] += addServer;
            answer += addServer;
            
            for (int j = i; j < i + k; j++) 
            {
                if (j > playerCount) 
                {
                    break;
                }
                
                servers[j] += addServer;
            }
        }
    }
    
    return answer;
}