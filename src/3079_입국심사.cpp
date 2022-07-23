#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long N, M;

vector<int> v; // ½Ã°£

int main()
{
    scanf("%d %d", &N, &M);

    int d;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &d);

        v.push_back(d);
    }

    sort(v.begin(), v.end());

    long long start = v[0];
    long long end = v[v.size() - 1] * M;
    long long answer;

    while (start <= end)
    {
        long long mid = (start + end) / 2;

        long long cnt = 0;

        for (int i = 0; i < N; i++)
        {
            cnt += mid / v[i];
        }

        if (cnt < M)
            start = mid + 1;
        else
        {
            answer = mid;
            end = mid - 1;
        }
    }

    printf("%lld", answer);

    return 0;
}
