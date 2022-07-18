#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, K;
bool Visited[200001];

queue<pair<int, int>> q; // first : idx, second : cnt

int time = 0, cnt = 0;

void BFS()
{
    while (!q.empty())
    {
        auto i = q.front();
        q.pop();

        Visited[i.first] = true;

        if (!time && i.first == K)
        {
            time = i.second;
            cnt++;
            continue;
        }

        if (time && i.first == K && i.second == time)
        {
            cnt++;
            continue;
        }


        if (i.first < 100000 && !Visited[i.first + 1])
            q.push(make_pair(i.first + 1, i.second + 1));
        if (i.first > 0 && !Visited[i.first - 1])
            q.push(make_pair(i.first - 1, i.second + 1));
        if (i.first < 100000 && !Visited[i.first * 2])
            q.push(make_pair(i.first * 2, i.second + 1));
    }
}

int main() {

    scanf("%d %d", &N, &K);

    q.push(make_pair(N, 0));

    BFS();

    printf("%d\n%d", time, cnt);

    return 0;
}