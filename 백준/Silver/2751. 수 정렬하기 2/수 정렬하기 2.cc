#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> tmp;

void Sort(int start, int end)
{
    if (end - start < 1)
        return;

    int mid = start + (end - start) / 2;

    Sort(start, mid);
    Sort(mid + 1, end);

    // 임시 배열에 값 저장.
    for (int i = start; i <= end; i++)
    {
        tmp[i] = v[i];
    }

    int k = start;
    int index1 = start;
    int index2 = mid + 1;

    while (index1 <= mid && index2 <= end)
    {
        if (tmp[index1] > tmp[index2])
        {
            v[k] = tmp[index2];
            k++;
            index2++;
        }
        else
        {
            v[k] = tmp[index1];
            k++;
            index1++;
        }
    }

    while (index1 <= mid)
    {
        v[k] = tmp[index1];
        k++;
        index1++;
    }

    while (index2 <= mid)
    {
        v[k] = tmp[index2];
        k++;
        index2++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    v = vector<int>(N + 1, 0);
    tmp = vector<int>(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    Sort(1, N);

    for (int i = 1; i <= N; i++)
    {
        cout << v[i] << '\n';
    }
}