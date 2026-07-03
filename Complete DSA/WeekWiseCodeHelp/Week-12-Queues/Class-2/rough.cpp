# include<bits/stdc++.h>
using namespace std; 

vector<int> findNegElement(vector<int>&v,int k){
    int n = v.size();
    vector<int>ans;
    deque<int>q;

    for(int i=0;i<k;i++){
        int ele = v[i];
        if(ele<0){
            q.push_back(i);
        }
    }
    if(q.empty()){
        ans.push_back(0);
    }
    else{
        ans.push_back(v[q.front()]);
    }

    for(int i=k;i<n;i++){
        int ele = v[i];
        if(!q.empty() && q.front()<i-k+1){
            q.pop_front();
        }

        if(ele<0){
            q.push_back(i);
        }

        if(q.empty()){
        ans.push_back(0);
        }
        else{
            ans.push_back(v[q.front()]);
        }
    }
    return ans;

}
int main(){
    // task to find all -ve numbers of window size = 2
    vector<int>v = {-8,2,3,-6,10};
    int k = 2;

    auto ans = findNegElement(v,k);
    for(auto i: ans){
        cout<<i<<" ";
    }
 return 0;
}