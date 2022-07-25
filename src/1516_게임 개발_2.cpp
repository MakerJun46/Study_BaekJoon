#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N;

vector<int> Nodes[501];
vector<int> indegreeRecord[501];
int indegree[501];
int times[501];

int main() {

    scanf("%d", &N);

    int t, d;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &t);

        times[i] = t;

        scanf("%d", &d);

        while (d != -1)
        {
            Nodes[d].push_back(i);
            indegreeRecord[i].push_back(d);
            indegree[i]++;

            scanf("%d", &d);
        }
    }

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int item = q.front();

        q.pop();

        for (int j : Nodes[item])
        {
            indegree[j]--;

            if (indegree[j] == 0)
            {
                int maxTime = 0;

                for (int k : indegreeRecord[j])
                {
                    if (maxTime < times[k])
                        maxTime = times[k];
                }

                times[j] += maxTime;

                q.push(j);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", times[i]);
    }

    return 0;
}