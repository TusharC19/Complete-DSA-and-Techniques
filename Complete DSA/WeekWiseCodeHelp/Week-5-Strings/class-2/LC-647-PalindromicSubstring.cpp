# include<bits/stdc++.h>
using namespace std; 

// int main(){
//     string s = "hello";
//     int cnt = 0;
//     for(int i=0;i<s.length();i++){
//         for(int j=i;j<s.length();j++){
//             for(int k=i;k<=j;k++){
//                 cout<<s[k]<<" ";               
//             }
//             cout<<endl;
//             cnt++;
//         }       
//     }
//     cout<<"no of substring: "<<cnt<<endl;
//  return 0;
// }

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

int expandaroundcenter(string &s,int i,int j){
    int cnt = 0;
    while(i>=0 && j<s.length() && s[i]==s[j]){
        cnt++;
        i--;
        j++;
    }
    return cnt;

}

int PalindromicSubstr(string &s){

    int totalcnt = 0;
    int i,j;
    for(int center=0;center<s.length();center++){
        // even case
        j=center+1;
        i=center;
        int evencnt = expandaroundcenter(s,i,j);

        // odd case
        i=center;
        j=center;
        int oddcnt = expandaroundcenter(s,i,j);

        totalcnt += evencnt + oddcnt;
    }
    
    return totalcnt;
}


int main(){

    string s1 = "madam";
    string s2 = "babbar";

    cout<<PalindromicSubstr(s1)<<endl;


    
}












