# include<bits/stdc++.h>
using namespace std; 

int main(){
    
    unordered_map<int,string>mapp;
    mapp[1] = "rohan";
    mapp[2] = "akash"; 
    mapp[3] = "sameer"; 
    mapp[4] = "karan"; 

    // SEARCHING IN MAP
    // count(),find()
    
    // if(mapp.find(2) != mapp.end()) cout<<"present"<<endl;
    // else cout<<"not present"<<endl;

    // if(mapp.count(2) != 0) cout<<"present"<<endl;
    // else cout<<"not present"<<endl;

    unordered_map<string,string>m;
    m["apple"] = "red";
    m["mango"] = "yellow";

    for(auto &it : m){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    // Note yha pe constructor me first and econd use kar sakte hai



 return 0;
}