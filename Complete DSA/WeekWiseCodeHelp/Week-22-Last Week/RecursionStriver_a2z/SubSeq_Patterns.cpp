#include <bits/stdc++.h>
using namespace std;

void pSubSeq(int i, vector<int> &v, vector<int> &a, int s)
{
    int n = v.size();

    if (i >= n)
    {
        if (s == 0)
        {
            for (int &i : a)
                cout << i << " ";
            cout << endl;
        }
        return;
    }

    // add kiya
    a.push_back(v[i]);
    s -= v[i];
    // call next
    pSubSeq(i + 1, v, a, s);
    // wapas aya
    // remove kiya
    a.pop_back();
    // exclude kiya
    pSubSeq(i + 1, v, a, s);

    return;
}
void pSum(vector<int> &v, int sum)
{
    vector<int> a;
    pSubSeq(0, v, a, sum);
}
// for print just one with s == sum
// bool flag = false;  // Global variable
bool psum2(int i, vector<int> &ds, int s, int sum, vector<int> &v)
{
    if (i >= v.size())
    {
        if (s == sum)
        {
            for (int &i : ds)
                cout << i << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    ds.push_back(v[i]);
    s += v[i]; // take
    if (psum2(i + 1, ds, s, sum, v) == true)
    {
        return true;
        // no need to do further recursion calls
    }

    // wrna niche wala recursion call hoga
    // coming back
    ds.pop_back();
    s -= v[i]; // not take
    if (psum2(i + 1, ds, s, sum, v) == true)
    {
        return true;
    }

    // dono me se koi bhi true nhi aya
    return false;
}

int subseqCntHelper(int i, vector<int> &v, int k)
{
    if (i >= v.size())
    {
        if (k == 0)
            return 1;
        return 0;
    }

    // here we are not checking the length so we not add anything

    int inc = subseqCntHelper(i + 1, v, k - v[i]);
    int exc = subseqCntHelper(i + 1, v, k);

    int cnt = inc + exc;
    return cnt;
}
// count all subsequences whose sum is equal to k
int subSeqCnt(vector<int> &v, int k)
{
    int i = 0;
    int cnt = subseqCntHelper(i, v, k);
    return cnt;
}

// longest subseq of sum = k
int longestSubSeqofSumKHelper(int i, vector<int> &v, int k)
{
    if (i >= v.size())
        return 0;
    if (k == 0)
        return 0;

    int inc = 1 + longestSubSeqofSumKHelper(i + 1, v, k - v[i]);
    int exc = 0 + longestSubSeqofSumKHelper(i + 1, v, k);

    int maxlen = max(inc, exc);
    return maxlen;
}

int longestSubSeqofSumK(vector<int> &v, int k)
{
    int i = 0;
    int len = longestSubSeqofSumKHelper(i, v, k);
    return len;
}

int main()
{
    vector<int> v = {1, 2, 1, 3};
    vector<int> ds;
    int s = 0, sum = 2;
    // to print only 1 subseqences that matches the condition
    bool ans = psum2(0, ds, s, sum, v);

    int k = 4;
    // int ans = subSeqCnt(v,k);
    // int ans = longestSubSeqofSumK(v,k);
    // cout<<ans<<endl;

    return 0;
}