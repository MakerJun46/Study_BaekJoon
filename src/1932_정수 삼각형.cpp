#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;

vector<int> DP[501];

int main()
{
    scanf("%d", &N);

    int d;

    for (int i = 1; i <= N; i++)
    {
        vector<int> tmp;

        for (int j = 0; j < i; j++)
        {
            scanf("%d", &d);

            tmp.push_back(d);
        }

        DP[i] = tmp;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j == 0) // 첫번째 원소 : 맨 왼쪽 => 오른쪽 위 선택지밖에 없음
                DP[i][j] += DP[i - 1][j];
            else if (j == i - 1) // 마지막 원소 : 맨 오른쪽 => 왼쪽 위 선택지밖에 없음
                DP[i][j] += DP[i - 1][j - 1];
            else
            {
                DP[i][j] += max({ DP[i - 1][j - 1], DP[i - 1][j] });
            }
        }
    }

    printf("%d", *max_element(DP[N].begin(), DP[N].end()));

    return 0;
}
