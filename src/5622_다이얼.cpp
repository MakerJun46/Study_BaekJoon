#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int dial[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6 ,6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };

	int time = 0;

	for (char c : s)
	{		
		time += dial[c - 'A'] + 1;
	}

	cout << time;

	return 0;
}