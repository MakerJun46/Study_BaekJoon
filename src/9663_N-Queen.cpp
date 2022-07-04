#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
int answer = 0;
int col[15];

bool check(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (col[i] == col[row] || abs(col[row] - col[i]) == row - i)
			return false;
		// col[i] == col[row] => 이미 같은 라인(가로, 세로)에 놓은 경우
		// |x - y| 와 row(y) - i(x) 가 같다면 대각선에 놓인 것
	}

	return true;
}

void dfs(int x)
{
	if (x == N)
		answer++;
	else
	{
		for (int i = 0; i < N; i++) // i => 해당 row, 한줄에 하나만 놓을 수 있으니까
		{
			col[x] = i;

			if (check(x))
				dfs(x + 1);
		}
	}
}

int main()
{
	cin >> N;

	dfs(0);

	cout << answer;

	return 0;
}