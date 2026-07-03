#include <bits/stdc++.h>
using namespace std;

// 7. Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

int reverseInt(int num)
{
    if (num <= INT_MIN || num >= INT_MAX)
        return 0;

    int m = num;
    num = abs(num);
    int ans = 0;
    while (num > 0)
    {
        // for ans*10>
        if (ans > INT_MAX / 10)
            return 0;
        int d = num % 10;
        ans = ans * 10 + d;
        num /= 10;
    }

    if (m < 0)
        ans = -1 * ans;
    return ans;
}

int main()
{
    int a = INT_MIN;
    cout << reverseInt(a) << endl;

    return 0;
}