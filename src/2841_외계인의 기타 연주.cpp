#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, P;

priority_queue<int> guitar[7];

int main() {

    scanf("%d %d", &N, &P);

    int a, b;
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);

        while (!guitar[a].empty() && guitar[a].top() > b)
        {
            guitar[a].pop();
            ans++;
        }

        if (!guitar[a].empty() && guitar[a].top() == b)
        {
            continue;
        }
        else
        {
            guitar[a].push(b);
            ans++;
        }
    }

    printf("%d", ans);

    return 0;
}