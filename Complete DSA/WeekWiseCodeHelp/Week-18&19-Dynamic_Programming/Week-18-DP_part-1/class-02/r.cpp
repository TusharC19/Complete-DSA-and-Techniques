# include<bits/stdc++.h>
using namespace std; 

int main(){
    // string s = "abc";
    // reverse(s.begin(),s.end());
    // string m = s;
    // cout<<m<<endl;


    map<int,string>mapp; // this works unordered map not
    mapp[1] = "india";
    mapp[2] = "japan";
    mapp[3] = "china";

    // for(auto it: mapp) cout<<it.first<<"->"<<it.second<<endl;
    // auto it = mapp.find(4);
    // if(it != mapp.end()) cout<<"present"<<endl;
    // else cout<<"absent"<<endl;

    // for(auto it: mapp){
    //     if(it.first == 3) break;
    //     cout<<"hello"<<endl;
    // }

    string s = "abc";
    string currword = s;
    reverse(s.begin(),s.end());
    cout<<s<<" "<<currword<<endl;



 return 0;
}