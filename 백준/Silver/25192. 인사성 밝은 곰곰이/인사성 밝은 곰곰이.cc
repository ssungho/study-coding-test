#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string tag;
    cin >> tag;

    set<string> s;
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {

        string temp;
        cin >> temp;

        if (tag == temp)
        {
            s.clear();
        }
        else
        {
            if (s.find(temp) == s.end())
            {
                s.insert(temp);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}