# include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n,vector<int>&ans){
    stack<int>s;
    // initially stack me -1 store kra liya hai
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        int element = arr[i];

        while(s.top()>element){
            s.pop();
        }
        /// yha tak aya yani stack ke top me 
        // smaller value hai than element
        // ans me store kr liya
        ans.push_back(s.top());
        s.push(element);
    }
}


int main(){

    int arr[] = {8,4,6,2,3};

    vector<int>ans;

    solve(arr,5,ans);
    reverse(ans.begin(),ans.end());
    for(auto i: ans){
        cout<<i<<" ";
    }
    
    return 0;
}