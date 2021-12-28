#include <iostream>

using namespace std;

int main()
{
	int kg;

	cin >> kg;

	int five_kg;
	int three_kg;

	five_kg = kg / 5;

	while (1)
	{
		if (five_kg < 0)
		{
			cout << -1;
			return 0;
		}

		if ((kg - five_kg * 5) % 3 == 0)
		{
			three_kg = (kg - five_kg * 5) / 3;
			break;
		}
		five_kg--;
	}

	cout << five_kg + three_kg;
	
	return 0;
}