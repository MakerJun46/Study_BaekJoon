#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N, K;
int ptrA = 2, ptrB = 3;
bool isPrime[1000001];

void findPrimes()
{
    isPrime[1] = true;

    for (int i = 2; i <= sqrt(1000000); i++)
    {
        if (isPrime[i])
            continue;

        for (int j = i * i; j <= 1000000; j += i)
        {
            isPrime[j] = true;
        }
    }

    isPrime[2] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    findPrimes();

    cin >> N;

    while (N != 0)
    {
        ptrA = 1; ptrB = N; 

        bool isWrong = false;

        while(true)
        {
            while (isPrime[ptrA])
                ptrA++;
            while (isPrime[ptrB])
                ptrB--;

            if (ptrA + ptrB == N)
                break;

            if (ptrA + ptrB > N)
            {
                ptrB--;
            }
            else if (ptrA + ptrB < N)
            {
                ptrA++;
            }

            if (ptrA > ptrB)
            {
                isWrong = true;
                break;
            }
        }

        if (isWrong)
            cout << "Goldbach's conjecture is wrong\n";
        else
            cout << N << " = " << ptrA << " + " << ptrB << "\n";

        cin >> N;
    }

    return 0;
}