#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N, M;
int DisjointSet[1000001];

int Find(int idx)
{
    if (DisjointSet[idx] == idx)
        return idx;
    else
        return DisjointSet[idx] = Find(DisjointSet[idx]);
}

void Union(int from, int to)
{
    int fromIdx = Find(DisjointSet[from]);
    int toIdx = Find(DisjointSet[to]);

    DisjointSet[toIdx] = fromIdx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i < N + 1; i++)
    {
        DisjointSet[i] = i;
    }

    int order, a, b;

    for (int i = 0; i < M; i++)
    {
        cin >> order >> a >> b;
    
        if (order == 0)
        {
            Union(a, b);
        }
        else
        {
            if (Find(a) == Find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}