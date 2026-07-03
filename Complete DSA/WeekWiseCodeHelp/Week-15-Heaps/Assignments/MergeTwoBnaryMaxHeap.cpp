#include <bits/stdc++.h>
using namespace std;

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here
    priority_queue<int> pq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
        pq.push(a[i]);
    for (int i = 0; i < m; i++)
        pq.push(b[i]);

    while (!pq.empty())
    {
        int ele = pq.top();
        pq.pop();
        ans.push_back(ele);
    }

    return ans;
}

int main()
{
    int n = 4, m = 3;
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    auto ans = mergeHeaps(a,b,n,m);
    for(int i: ans) cout<<i<<" ";
    cout<<endl;

    return 0;
}