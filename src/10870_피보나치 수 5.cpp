#include <iostream>

using namespace std;

int fibonachi(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fibonachi(n - 2) + fibonachi(n - 1);
}

int main()
{
	int N;

	cin >> N;
	
	cout << fibonachi(N);

	return 0;
}