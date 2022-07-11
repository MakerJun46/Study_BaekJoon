#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 위상정렬

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<int> inDegree(N);
    vector<vector<int>> Students(N);

    for (int i = 0; i < M; i++)
    {
        int cmp1, cmp2;

        cin >> cmp1 >> cmp2;

        cmp1--; cmp2--;

        inDegree[cmp2]++;

        Students[cmp1].push_back(cmp2);
    }

    queue<int> q;

    int startIdx = find(inDegree.begin(), inDegree.end(), 0) - inDegree.begin();

    q.push(startIdx);

    while (!q.empty())
    {
        int idx = q.front(); q.pop();

        inDegree[idx] = -1;

        for (int i = 0; i < (int)Students[idx].size(); i++)
        {
            inDegree[Students[idx][i]]--;
        }

        auto it = find(inDegree.begin(), inDegree.end(), 0);

        if (it != inDegree.end())
        {
            q.push(it - inDegree.begin());
        }

        cout << idx + 1 << " ";
    }

    return 0;
}