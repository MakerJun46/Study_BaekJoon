#include <iostream>
#include <math.h>

using namespace std;

int N, K;

int factorial(int num)
{
    int f = 1;

    for (int i = 1; i <= num; i++)
    {
        f *= i;
    }

    return f;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    // nCk

    cout << factorial(N) / (factorial(K) * factorial(N - K)) << "\n";

    return 0;
}
