#include <iostream>
#include <vector>
#include <string>
#include<memory.h>

using namespace std;

bool visited[50][50] = {false,};
char map[50][50];
int dp[50][50] = { -1, };
bool isLoop = false;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M;

int dfs(int n, int m)
{
	if (n < 0 || n >= N || m < 0 || m >= M)
		return 0;

	if (map[n][m] == 'H')
	{
		return 0;
	}

	if (visited[n][m])
	{
		isLoop = true;
		return 0;
	}

	int& ret = dp[n][m];
	if (ret != -1) return ret;

	visited[n][m] = true; // ¹æ¹® Áß

	for (int i = 0; i < 4; i++)
	{
		int mx = n + (map[n][m] - '0') * dx[i];
		int my = m + (map[n][m] - '0') * dy[i];
	
		int val = dfs(mx, my) + 1;
		ret = max(ret, val);
	}

	visited[n][m] = false;
	
	return ret;
}

int main()
{
	cin >> N >> M;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char data;

			cin >> data;

			map[i][j] = data;
		}
	}

	int answer = dfs(0, 0);

	if (isLoop)
		cout << -1;
	else
		cout << answer;

	return 0;
}