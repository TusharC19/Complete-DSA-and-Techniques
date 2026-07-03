# include<bits/stdc++.h>
using namespace std; 

vector<int> maxSubsequence(vector<int>& a, int k) {
        int n = a.size();
        vector<int>ans;

        if(k==a.size()) return a;
        // nth element
        vector<int>temp = a;
        nth_element(temp.begin(),temp.begin()+k-1,temp.end(),greater<int>());

        int nthLargest = temp[k-1];
        int cntNthLargest = 0;
        for(int i=0;i<k;i++) 
            if(a[i]==nthLargest) cntNthLargest++; 
        
        for(int i=0;i<n && cntNthLargest != cntNthLargest-1;i++){
            if(a[i]<nthLargest) continue;
            else{
                if(a[i]==nthLargest){
                    ans.push_back(a[i]);
                    cntNthLargest--;
                }
                else{
                    ans.push_back(a[i]);
                }
            }
        }

        return ans;

        
    }

int main(){
        vector<int>a = {-1,-2,3,4};
        int k = 3;
        auto ans = maxSubsequence(a,k);
        for(int i:ans) cout<<i<<" ";
        cout<<endl;

 return 0;
}