# include<bits/stdc++.h>
using namespace std; 

bool checkPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++,j--;
            }
            else{
                return false;
            }
        }
        return true;
}

bool validPalidrome(string s){
    int i = 0,j=s.length()-1;
    while(i<=j){
        if(s[i]==s[j]) i++,j--;
        else{
            // not same check by deleting character
            bool ansOne = checkPalindrome(s,i+1,j);
            
            bool ansTwo = checkPalindrome(s,i,j-1);
            // dono me se koi bhi ek case true ho chlega
            bool finalAns = ansOne || ansTwo;
            return finalAns;

            // !!! NOTE: Here humne ek baar delete krke ans return kr diya 
            // Make sure ki again loop me na ghume

        }
        // yha tak aya matlab without delete kre palindrome hai
        
    }
    return true;
}

int main(){

    string s = "rabbdbcar";
    if(validPalidrome(s)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

 return 0;
}
