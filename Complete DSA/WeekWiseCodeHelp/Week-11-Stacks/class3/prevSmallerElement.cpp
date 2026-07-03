# include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n,vector<int>&ans){
    stack<int>s;
    s.push(-1);
    
    for(int i=0;i<n;i++){
        int element = arr[i];

        while(s.top()>element){
            s.pop();
        }
        /// yha tak aya yani chota element mil
        /// gya hai
        //// store in ans
        ans.push_back(s.top());
        s.push(element);
    }


}


int main(){
    
    int arr[] = {8,4,2,6,3};
    int n = 5;
    vector<int>ans;
    solve(arr,n,ans);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}