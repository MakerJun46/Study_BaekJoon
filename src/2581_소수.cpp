#include <iostream>
using namespace std;

int main()
{
	int M, N;

	cin >> M >> N;

	int minPrime = 0;
	int sumPrime = 0;

	for (int i = M; i <= N; i++)
	{
		if (i == 1)
			continue;

		bool isPrime = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			sumPrime += i;

			if (minPrime > i)
				minPrime = i;
		}
	}
	
	if (sumPrime == 0)
		cout << -1;
	else
		cout << sumPrime << endl << minPrime;

	return 0;
}