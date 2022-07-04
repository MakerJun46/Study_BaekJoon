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
		// col[i] == col[row] => �̹� ���� ����(����, ����)�� ���� ���
		// |x - y| �� row(y) - i(x) �� ���ٸ� �밢���� ���� ��
	}

	return true;
}

void dfs(int x)
{
	if (x == N)
		answer++;
	else
	{
		for (int i = 0; i < N; i++) // i => �ش� row, ���ٿ� �ϳ��� ���� �� �����ϱ�
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