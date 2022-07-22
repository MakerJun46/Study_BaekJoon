#include <cstdio>
#include <vector>

using namespace std;

int N, M;

vector<int> arr;
vector<bool> Visited;
vector<int> v;

void print()
{
    for (int i : v)
        printf("%d ", i);

    printf("\n");
}

void dfs(int cnt)
{
    if (cnt == M)
    {
        print();
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (Visited[i])
            continue;

        Visited[i] = true;
        v.push_back(arr[i]);
        dfs(cnt + 1);
        v.pop_back();
        Visited[i] = false;
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        arr.push_back(i);
        Visited.push_back(false);
    }

    dfs(0);

    return 0;
}
