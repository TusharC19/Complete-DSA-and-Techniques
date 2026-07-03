# include<bits/stdc++.h>
using namespace std; 

// previous smaller element pattern

vector<int> pse(vector<int> &heights){
        int n = heights.size();
        vector<int>ans;
        stack<int>s;
        s.push(-1);

        for(int i=0;i<n;i++){
            int m = heights[i];

            while( s.top()!= -1 && m<=heights[s.top()]){
                s.pop();
            }

            ans.push_back(s.top());
            s.push(i);
        }

        return ans;
    }

int main(){

    vector<int>v = {3,1,2,4};

    auto ans1 = pse(v);
    // reverse(ans1.begin(),ans1.end());
    // for(int i=0;i<v.size();i++){
    //     if(ans1[i] == -1) 
    //         ans1[i] = v.size();
    // }
    for(auto i: ans1){
        cout<<ans1[i]<<" ";
    }
   

    
   

    

    


    







 return 0;
}