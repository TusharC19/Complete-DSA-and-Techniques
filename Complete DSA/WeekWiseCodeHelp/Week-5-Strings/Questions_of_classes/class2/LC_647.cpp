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

int expandAroundCenter(string s,int i,int j){
    int n = s.size();

    int cnt = 0;
    while(i>=0 && j<n && s[i]==s[j]){
        cnt++;
        i--,j++; 
    }
    return cnt;
}


int countSubstrings(string s) {
    int n  = s.size();
    int totalcnt=0;

    for(int center=0;center<n;center++){

        // odd length
        int i=center,j=center;
        int oddlencnt = expandAroundCenter(s,i,j);
        // even length substrings
        i = center,j=center+1;
        int evenlencnt = expandAroundCenter(s,i,j);

        totalcnt += (oddlencnt + evenlencnt);
        
    }

    return totalcnt;

}

int main(){
    string s = "babbar";
    int ans = countSubstrings(s);
    cout<<ans<<endl;



    
 return 0;
}