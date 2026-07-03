// Leetcode 84
// Histogram

class Solution {
public:
    void nextsmall(vector<int>&heights,vector<int>&next){
        stack<int>s;
        s.push(-1);
        int n = heights.size();

        for(int i=n-1;i>=0;i--){
            int element = heights[i];

            while(s.top() != -1 && element<=heights[s.top()]){
                s.pop();
            }
            // yaha tak aya hu matlab mera top of stack
            // ya toh -1 hai ya smaller than element hai or equal bhi ho sakta hai
            next.push_back(s.top());
            s.push(i);
        }
    }

    void prevsmall(vector<int>&heights,vector<int>&next){
        stack<int>s;
        s.push(-1);
        int n = heights.size();

        for(int i=0;i<n;i++){
            int element = heights[i];
            // corner case mein bhul gya <= hoga
            while(s.top() != -1 && element<=heights[s.top()]){
                s.pop();
            }
            // yaha tak aya hu matlab mera top of stack
            // ya toh -1 hai ya smaller than element hai
            next.push_back(s.top());
            s.push(i);
        }
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int>next;
        vector<int>prev;

        nextsmall(heights,next);
        // is case me reverse karana pdta hai
        reverse(next.begin(),next.end());
        /// jha pe bhi -1 hoga vha pe size of next
        // insert kra do 
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i] = next.size();
            }
        }
        prevsmall(heights,prev);
        // ab mere dono smaller ke index store ho chuke hai

        /// now mujhe yha each element ka area
        // calculate karke dekhna hai
        // then max area calculate karna hai

        int maxArea = INT_MIN;
        for(int i=0;i<next.size();i++){
            int width = next[i] - prev[i] - 1;
            int height = heights[i];
            int currArea = height * width;
            maxArea = max(maxArea,currArea);
        }

        return maxArea;

        

    }
};