// 50. Pow(x, n) Leetcode

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double iterative(double x, int a)
{
    ll m = a;
    double ans = 1.0;
    ll n = llabs(a);

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = (ans * x);
            n = n - 1;
        }
        else
        {
            n = n / 2;
            x = (x * x);
        }
    }

    if (m < 0)
        ans = 1.0 / ans;
    return ans;
}

int M=1e9+7;
int iterative2(int x, int a)
{   
    int m = a;
    int ans = 1;
    int n=abs(a);

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = (ans * x)%M;
            n = n - 1;
        }
        else
        {
            n = n / 2;
            x = (x * x)%M;
        }
    }

    if (n < 0)
        ans = 1 / ans;
    return ans;
}

double findPower(int x, int n)
{
    return iterative2(x, n);
}

int main()
{

    return 0;
}