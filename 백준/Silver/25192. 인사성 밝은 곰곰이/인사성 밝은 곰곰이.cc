#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{

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