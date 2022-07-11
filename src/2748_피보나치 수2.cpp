#include <iostream>

using namespace std;

int N;

long long dp[91];

long long fibo(long long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (dp[n] != 0)
        return dp[n];
    else if (dp[n] == 0)
    {
        dp[n] = fibo(n - 1) + fibo(n - 2);
        return dp[n];
    } 
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> N;

    cout << fibo(N);

    return 0;
}
