#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<bool> numbers(10001, false);

	for (int i = 1; i < 10001; i++)
	{
		int tmp = i;
		int self_number = i;
		while (tmp > 0)
		{
			self_number += tmp % 10;
			tmp /= 10;
		}

		if(self_number < 10001)
			numbers[self_number] = true;
	}

	for (int i = 1; i < 10001; i++)
	{
		if (!numbers[i])
			cout << i << "\n";
	}

	return 0;
}