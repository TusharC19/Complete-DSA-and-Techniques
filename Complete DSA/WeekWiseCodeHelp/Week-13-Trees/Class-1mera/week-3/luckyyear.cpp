
// int main(){
//     // int n;cin>>n;
//     int n = 10030;
//     string s = to_string(n);
//     cout<<s<<endl;
//     // cout<<typeid(n).name()<<endl;

//  return 0;
// }

# include<bits/stdc++.h>
using namespace std; 

bool islucky(string &s){
    long long cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i] != '0') cnt++;
    }
    return cnt<=1;
}


int main(){
    int n;cin>>n;
    string s = to_string(n);

    if(n==1e9) cout<<0<<endl;

    long long m = n;
    long long i= 1;
    while(true){
        m += i;
        s = to_string(m);
        if(islucky(s)) break;
    }


    // difference 
    long long diff = m - n;
    cout<<diff<<"\n";

 return 0;
}