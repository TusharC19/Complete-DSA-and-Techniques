# include<bits/stdc++.h>
using namespace std; 

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<string>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int cnt=1;
        for(int i=1;i<n;i++){
            if(a[0] == a[i]){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
 return 0;
}