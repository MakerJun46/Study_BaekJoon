#include <cstdio>

using namespace std;

int N, M;

int mat[1025][1025];
int DP[1025][1025];

int main()
{
    scanf("%d %d", &N, &M);

    int d;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &d);

            mat[i][j] = d;
            
            // 2차원 배열 dp 에서
            // DP[i][j] => i x j 짜리 사각형의 오른쪽하단 까지 더한 값
            // 따라서 i - 1(위쪽) + j - 1(왼쪽)에서 겹치는 값 (i - 1)(j - 1)을 빼주고 입력값 더하면 된다!
            
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + d;
        }
    }

    int x1, y1, x2, y2, ans = 0;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        printf("%d\n", DP[x2][y2] - DP[x2][y1 - 1] - DP[x1 - 1][y2] + DP[x1 - 1][y1 - 1]);
    }


    return 0;
}
