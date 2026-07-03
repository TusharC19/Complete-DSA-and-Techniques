# include<bits/stdc++.h>
using namespace std; 

 vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // Your code goes here
        stack<int>s;
        int n=arr.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){

            while(!s.empty()&&arr[i] >= arr[s.top()]) s.pop();

            ans[i] = s.size();
            s.push(i);
        }

        vector<int>a;
        for(int i=0;i<indices.size();i++){
            a.push_back(ans[indices[i]]);
        }

        for(int i:ans) cout<<i<<" ";cout<<endl;


        return a;
}


int main(){
    vector<int>a = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int>ind={0,5};
    
    auto ans = count_NGE(a,ind);
    for(int i:ans) cout<<i<<" ";cout<<endl;
 return 0;
}
