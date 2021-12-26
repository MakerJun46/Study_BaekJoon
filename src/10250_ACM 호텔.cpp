#include <iostream>

using namespace std;

int main()
{
	int T;
	int H, W, N;

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> H >> W >> N;

		int h = (N % H == 0 ? H : N % H);
		int w = (N % H == 0 ? N / H : N / H + 1);

		if (w < 10)
			cout << h << "0" << w << endl;
		else
			cout << h << w << endl;
	}

	return 0;
}