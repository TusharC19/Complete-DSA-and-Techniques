#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegInt(vector<int> &arr, int k)
{
    // write code here
    int n = arr.size();
    vector<int> ans;
    deque<int> q;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            q.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        if (!q.empty())
            ans.push_back(arr[q.front()]);
        else
            ans.push_back(0);

        // removal
        if (!q.empty() && i - q.front() >= k)
            q.pop_front();

        // addition of curr element check
        if (arr[i] < 0)
            q.push_back(i);
    }

    if (!q.empty())
        ans.push_back(arr[q.front()]);
    else
        ans.push_back(0);

    return ans;
}

int main()
{
    vector<int> a = {10, -1, -2, 3, 4};
    int k = 2;
    auto ans = firstNegInt(a, k);
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}