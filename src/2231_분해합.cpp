#include <iostream>

using namespace std;

int main()
{
	int N;
	int constructor = 0;

	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int M = i;
		int sum = i;

		while (M > 0)
		{
			sum += M % 10;
			M /= 10;
		}

		if (sum == N)
		{
			constructor = i;
			break;
		}
	}

	cout << constructor;

	return 0;
}