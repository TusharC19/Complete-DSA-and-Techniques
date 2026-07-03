# include<bits/stdc++.h>
using namespace std; 

void nextSmaller(vector<int>&a){
        int n=a.size();
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            int ele = a[i];
            while(ele<s.top()){
                s.pop();
            }
            a[i] = s.top();
            s.push(ele);
        }
        
}

void prevSmaller(vector<int>&a){
        int n=a.size();
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            int ele = a[i];
            while(ele<s.top()){
                s.pop();
            }
            a[i] = s.top();
            s.push(ele);
        }
        
}

void nextGreater(vector<int>&a){
        int n=a.size();
        stack<int>s;
        s.push(100);
        for(int i=n-1;i>=0;i--){
            int ele = a[i];
            while(ele>=s.top()){
                s.pop();
            }
            a[i] = s.top();
            s.push(ele);
        }
        
}



// histogram

class Solution {
public:
    void nextSmaller(vector<int>&a,vector<int>&nsmaller){
        int n=a.size();
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            int ele = a[i];
            while(!s.empty() && s.top() != -1 && ele<=a[s.top()]){
                s.pop();
            }
            nsmaller.push_back(s.top());
            s.push(i);
        }
        
    }

    void prevSmaller(vector<int>&a,vector<int>&psmaller){
        int n=a.size();
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            int ele = a[i];
            while(!s.empty() && s.top() != -1  && ele<=a[s.top()]){
                s.pop();
            }
            psmaller.push_back(s.top());
            s.push(i);
        }
        

    }

    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        vector<int>psmaller;
        vector<int>nsmaller;
        nextSmaller(height,nsmaller);
        prevSmaller(height,psmaller);

        reverse(begin(nsmaller),end(nsmaller));

        for(int i=0;i<n;i++){
            if(nsmaller[i]==-1) nsmaller[i] = n;
        }

        int maxArea = -1;
        for(int i=0;i<n;i++){
            int h=height[i];
            int w=nsmaller[i]-psmaller[i]-1;
            int area = h*w;
            maxArea = max(maxArea,area);
        }

        return maxArea;

    }
};
// Till here

int main(){

    vector<int>a = {4,2,2,1,5,3};

    nextGreater(a);
    // reverse(ans.begin(),ans.end());
    // for(auto i: ans){
    //     cout<<i<<" ";
    // }
    for(int i:a) cout<<i<<" ";
    
    return 0;
}