#include <iostream>

using namespace std;

long long Ac, Ap, Bc, Bp;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Ac >> Ap;
    cin >> Bc >> Bp;

    long long p_gcd = gcd(Ap, Bp);
    long long p_icm = Ap * Bp / p_gcd;

    Ac = (p_icm / Ap) * Ac;
    Bc = (p_icm / Bp) * Bc;

    long long sum_p = p_icm;
    long long sum_c = Ac + Bc;

    p_gcd = gcd(sum_p, sum_c);

    while (p_gcd != 1)
    {
        p_gcd = gcd(sum_p, sum_c);

        sum_p /= p_gcd;
        sum_c /= p_gcd;
    }

    cout << sum_c << " " << sum_p;

    return 0;
}