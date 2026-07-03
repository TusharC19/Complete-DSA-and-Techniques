// Valid palindrome-II

# include<bits/stdc++.h>
using namespace std; 

bool check(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        else i++,j--;
        
    }
    return true;
}


bool validPalindrome(string s){
    int n = s.size();
    int i=0,j=n-1;

    while(i<=j){
        if(s[i]==s[j]) i++,j--;

        else{
            bool ans1 = check(s,i+1,j);
            bool ans2 = check(s,i,j-1);
            bool finalAns = ans1 || ans2;
            return finalAns;
        }
    }
    // without any deletion
    return true;
    
}


int main(){
    string s = "rabbcar";

    bool ans = validPalindrome(s);
    cout<<ans<<endl;
    
 return 0;
}