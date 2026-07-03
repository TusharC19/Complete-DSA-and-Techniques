# include<bits/stdc++.h>
using namespace std; 

vector<int> sum(vector<int>&v,vector<int>&a){
    vector<int>ans;
    int c=0;
    int i=v.size()-1,j=a.size()-1;
    while(i>=0 && j>=0){
        int sum = v[i] + a[j] +c;
        int digit = sum%10;
        c = sum/10;
        ans.push_back(digit);
        i--,j--;
    }

    while(i>=0){
        int sum = v[i]+ 0 +c;
        int digit = sum%10;
        c = sum/10;
        ans.push_back(digit);
        i--;
    }

    while(j>=0){
        int sum = a[j] +0 +c;
        int digit = sum%10;
        c = sum/10;
        ans.push_back(digit);
        j--;
    }
    if(c) ans.push_back(c);
    while(ans.back()==0) ans.pop_back();
    reverse(ans.begin(),ans.end());


    return ans;
}


int main(){
    vector<int>v = {0,9,0,0,3,5};
    vector<int>a = {0,0,0,2,2,7};
    auto ans = sum(v,a);

    for(auto i: ans){
        cout<<i<<"";
    }
 return 0;
}