#include <iostream>

using namespace std;

int main()
{
	int x;

	cin >> x;

	int stair = 1;

	while (x > stair + stair * (stair - 1) / 2)
		stair++;

	int stair_startNumber = (stair - 1) + ((stair - 1) * (stair - 2) / 2) + 1;
	int c = 0;
	int p = 0;

	stair % 2 == 0 ? p = stair, c = 1 : (p = 1, c = stair);
	
	for (int i = stair_startNumber; i < x; i++)
		stair % 2 == 0 ? p--, c++ : (p++, c--);

	cout << c << "/" << p;

	return 0;
}