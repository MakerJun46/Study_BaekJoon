#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<long long> trees;

int main() {

    scanf("%d %d", &N, &M);

    int d;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &d);

        trees.push_back(d);
    }

    long long start = 0;
    long long end = *max_element(trees.begin(), trees.end());
    long long ans;

    while (start <= end)
    {
        long long sum = 0;

        long long mid = (start + end) / 2;

        for (int i = 0; i < N; i++)
        {
            if(trees[i] > mid)
                sum += trees[i] - mid;
        }

        if (sum < M)
            end = mid - 1;
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}