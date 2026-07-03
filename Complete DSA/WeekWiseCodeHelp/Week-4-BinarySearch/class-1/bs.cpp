# include<bits/stdc++.h>
using namespace std; 


int32_t main(){
    vector<int>arr = {1,2,3,4,5,6};
    int n = arr.size(),t=4;

    bool ans = binary_search(arr.begin(),arr.end(),t);
    if(ans) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    
 return 0;
}