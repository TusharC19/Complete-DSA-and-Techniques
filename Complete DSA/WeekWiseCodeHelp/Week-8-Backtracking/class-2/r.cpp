# include<bits/stdc++.h>
using namespace std; 

void solve(string &st,int i,int s,string ans){
    if(i>=s){
        cout<<ans<<endl;
        return;
    }

    char ch = st[i];

    solve(st,i+1,s,ans + ch);

    solve(st,i+1,s,ans);

    return;
    
}


int sum(int n,int i){
    if(i>=n) return 0;

    int sum1 = i + sum(n,i+2);
    cout<<sum1<<" ";
    int sum2 = 0 + sum(n,i+1);
    cout<<endl;
    cout<<sum2<<" ";
    return max(sum1,sum2);
}

int main(){

    vector<vector<int>>v = {{1,2,3},{4,5,6},{7,8,9}};
    int r = v.size();
    int c = v[0].size();

    int n = v.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<< " ";

        }
        cout<<endl;
    }


        // string s = "abc",ans = "";
        // int i=0,n=s.size();
        // solve(s,i,n,ans);

        // int ans = sum(5,1);
        // cout<<ans<<endl;

 return 0;
}