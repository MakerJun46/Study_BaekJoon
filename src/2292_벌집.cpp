#include <iostream>

using namespace std;

int main()
{
	long long n;

	cin >> n;
	int x = 1;

	while (n > 3 *x * (x - 1) + 1)
		x++;

	cout << x;
	
	return 0;
}