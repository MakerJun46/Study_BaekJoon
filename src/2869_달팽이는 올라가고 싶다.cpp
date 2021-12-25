#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int a, b, v;

	cin >> a >> b >> v;

	int day = ceil((double)(v - b) / (a - b));

	cout << day;

	return 0;
}