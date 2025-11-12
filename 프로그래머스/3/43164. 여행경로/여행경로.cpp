#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> graph;
map<pair<string, string>, int> visited;
vector<string> paths;
vector<string> temp;
int target_cnt = 0;

void dfs(const string& here, int cnt) {
    if (paths.size() != 0) {
        return;
    }

    if (cnt == target_cnt) {
        if (paths.size() == 0) {
            paths = temp;
        }
        return;
    }

    const auto& cities = graph[here];
    for (const auto& city : cities) {
        if (visited[{here, city}] > 0) {
            visited[{here, city}]--;
            temp.push_back(city);
            dfs(city, cnt + 1);
            temp.pop_back();
            visited[{here, city}]++;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    map<string, vector<string>>().swap(graph);
    map<pair<string, string>, int>().swap(visited);
    paths.clear();
    temp.clear();
    target_cnt = tickets.size();
    
    for (const auto& v : tickets) {
        graph[v[0]].push_back(v[1]);
        visited[{v[0], v[1]}]++;
    }

    for (auto& p : graph) {
        sort(p.second.begin(), p.second.end());
    }

    temp.push_back("ICN");
    dfs("ICN", 0);
    answer = move(paths);
    
    return answer;
}