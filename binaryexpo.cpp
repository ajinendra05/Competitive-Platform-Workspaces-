#include <bits/stdc++.h>
using namespace std;
int fact[100];
const int m = 1e9 + 7;
void countFact()
{
    fact[0] = 1;
    for (int i = 1; i < 100; ++i)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % m;
    }
}

int binexp(int a, int b, int m)
{
    int result = 1;
    
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }

    return result;
}

int main()
{
    cout << binexp(2, m-2, m);
}