# include<bits/stdc++.h>
using namespace std; 

void printPermutations(string &s,int i){

    if(i>=s.length()) {
        cout<<s<<endl;
        return ;
    }

    // ek case mera baki recursion ka
    for(int j=i ;j<s.length(); j++){
        // swap kiya meine
        swap(s[i],s[j]);
        // baki recusrion dekh lega
        printPermutations(s,i+1);
        // wapas ate hai toh again swap kardo to nullify the effect
        swap(s[i],s[j]);

    }

    return;
}


int main(){
    
    string s = "ab";
    int size = s.size();
    printPermutations(s,0);


 return 0;
}