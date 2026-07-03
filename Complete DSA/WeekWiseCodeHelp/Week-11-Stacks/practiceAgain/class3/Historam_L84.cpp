class Solution {
public:

    vector<int> nse(vector<int> &heights){
        int n = heights.size();
        vector<int>ans;
        stack<int>s;
        s.push(-1);

        for(int i=n-1;i>=0;i--){
            int m = heights[i];

            while( s.top()!= -1 && m<=heights[s.top()]){
                s.pop();
            }

            ans.push_back(s.top());
            s.push(i);
        }

        return ans;
    }

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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        auto ans1 = nse(heights);
        for(int i=0;i<n;i++){
            if(ans1[i]==-1) ans1[i] = n;
        }
        reverse(ans1.begin(),ans1.end());
        // for(auto i: ans1){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        auto ans2 = pse(heights);
        // for(auto i: ans2){
        //     cout<<i<<" ";
        // }

        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            int w = ans1[i]-ans2[i]-1;
            int h = heights[i];
            int currArea = w*h;

            maxArea = max(maxArea,currArea);
        } 

        return maxArea;



        
    }
};