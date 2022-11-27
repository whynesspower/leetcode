#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool prime[100001];
void SieveOfEratosthenes(int n)
{

    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    SieveOfEratosthenes(100001);
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int temp = 0;
        for (int i = 2; i <= l; i++)
        {
            if (prime[i])
                temp++;
        }
        int ans = 0;
        if (temp != 0 && temp % 2 == 0)
            ans++;
        for (int i = l + 1; i <= r; i++)
        {
            if (prime[i])
            {
                temp++;
            }
            if (temp != 0 && temp % 2 == 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
