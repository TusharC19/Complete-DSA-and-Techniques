# include<bits/stdc++.h>
using namespace std; 

// for positive only
int lenOfLongestSubarr(vector<int>& a, int k) {
        // code here
        int n =a.size();
        
        int len=0,sum=0;
        
        int i=0,j=0;
        while(j<n){
            sum += a[j];
            
            if(sum==k){
                len = max(len,j-i+1);
            }
            else if(sum>k){
                sum -= a[i];
                i++;
            }
            j++;
            
        }
        return len;
}

int main(){
    vector<int>a = {10, 5, 2, 7, 1, 9};
    vector<int>b = {1,2,3,1,1,1,1,3,3};
    int k = 6;
    int Output = 4;

    int ans = lenOfLongestSubarr(b,k);
    cout<<ans<<endl;




 return 0;
}