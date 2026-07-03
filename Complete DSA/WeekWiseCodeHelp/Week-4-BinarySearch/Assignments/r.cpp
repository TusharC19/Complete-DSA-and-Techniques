#include <bits/stdc++.h>
using namespace std;


int solve(){
    int n;cin>>n;
    string s;cin>>s;
    
   
    int i=0;
    while(i<n && i+1<n){
        if(s[i]!=s[i+1]){
            s.erase(s.begin()+i);
            i++;
        }
        else i++;
    }

    return s.size();
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin>>t;
    while(t--)
    {
        int ans = solve();
        cout<<ans<<endl;
    }
    return 0;
}