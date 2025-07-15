#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr int A{0}, C{1}, G{2}, T{3};
int ranks[51][4];
int n, m;

int main(void) {
    cin >> n >> m;
    
    vector<string> DNAs;
    for (int i = 0; i < n; i++) {
        string DNA;
        cin >> DNA;
        DNAs.push_back(DNA);

        for (int j = 0; j < m; j++) {
            if (DNA[j] == 'A') ranks[j][A]++;
            else if (DNA[j] == 'C') ranks[j][C]++;
            else if (DNA[j] == 'G') ranks[j][G]++;
            else ranks[j][T]++;
        }
    }

    int hamming_distance = 0;
    string final_DNA = "";
    for (int i = 0; i < m; i++) {
        int ele = -1;
        int rank = -1;

        for (int j = 0; j < 4; j++) {
            if (rank < ranks[i][j]) {
                ele = j;
                rank = ranks[i][j];
            }
        }

        hamming_distance += (n - rank);

        char ch;

        if (ele == A) ch = 'A';
        else if (ele == C) ch = 'C';
        else if (ele == G) ch = 'G';
        else ch = 'T';

        final_DNA += ch;
    }

    cout << final_DNA << '\n' << hamming_distance << '\n';

    return 0;
}