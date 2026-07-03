# include<bits/stdc++.h>
using namespace std; 




int main(){
    int n = 4;
    vector<vector<char>>v(n,vector<char>(n,'.'));
    vector<vector<string>>a = { 
                                {".Q..","...Q","Q...","..Q."},
                                {"..Q.","Q...","...Q",".Q.."}
                                };


    vector<vector<string>>ans;
    vector<string>b;
    string s;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;

        
    }
    // Q . . . 
    // . . . .
    // . . . Q
    // . . . .



 return 0;
}