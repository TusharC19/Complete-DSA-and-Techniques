# include<bits/stdc++.h>
using namespace std; 

// find -ve element in every window 
vector<int> slidingWindow(vector<int>&arr,int k){
    int n = arr.size();
    vector<int>ans;
    deque<int>q;

    // process first window
    for(int i=0;i<k;i++){
        int ele = arr[i];
        if(ele<0){
            q.push_back(i);
        }
    }
    // store ans for first window
    if(q.empty()){
        ans.push_back(0);
    }
    else{ 
        // here queue not empty
        int idx = q.front();
        int eletopush = arr[idx];
        ans.push_back(eletopush);
    }

    // process remaining window
    for(int i=k;i<n;i++){
        int ele = arr[i];
        // deletion 
        if(!q.empty() && i-q.front()>=k){
            q.pop_front();
        }

        // addition        
        if(ele<0){
            q.push_back(i);
        }

        // ans store 
        if(q.empty()){
        ans.push_back(0);
        }
        else{ 
            // here queue not empty
            int idx = q.front();
            int eletopush = arr[idx];
            ans.push_back(eletopush);
        }
    }

    return ans;
}

int main(){

    // task to find all -ve numbers of window size = 2
    vector<int>v = {-8,2,3,-6,10};
    int k = 2;

    auto ans = slidingWindow(v,k);
    for(auto i: ans){
        cout<<i<<" ";
    }


    
 return 0;
}