#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;

	int count = 0;


	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		bool isPrime = n == 1 ? false : true;

		for (int j = 2; j < n; j++)
		{
			if (n % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			count++;
	}

	cout << count;

	return 0;
}