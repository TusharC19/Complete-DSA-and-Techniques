# include<bits/stdc++.h>
using namespace std; 


class Item{
    public:
    int data;
    int rIndex;
    int cIndex;

    Item(int data,int rIndex,int cIndex){
        this->data = data;
        this->rIndex = rIndex;
        this->cIndex = cIndex;
    }
};

class compare{
    public:
        // star isliye pass kiya kyunki copy nhi lena chahte hai
        // so object copy nhi hua original object hi liya hai
        bool operator()(Item* a,Item* b){
            // ye min hep bnata hai 
            // bigger element niche hoga and smaller uppar
            return a->data > b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& arr) {
        // yha bhi same original object liya hai usko dal rhe hai na ki copy
        priority_queue<Item*,vector<Item*>,compare>pq;
        vector<int>ans;


        int maxi=INT_MIN;
        int mini = INT_MAX;

        int start = 0;
        int end = 0;

        int totalrows = arr.size();

        for(int row=0;row<totalrows;row++){
            int ele = arr[row][0];
            Item* item = new Item(ele,row,0);
            mini = min(ele,mini);
            maxi = max(ele,maxi);
            pq.push(item);
        }

        // initially
        start = mini;
        end = maxi;
        
        // main logic of processing the data
        while(!pq.empty()){
            Item* front = pq.top();
            pq.pop();

            int num = front->data;
            int rindex = front->rIndex;
            int cindex = front->cIndex;

            // mini always top element hoga
            mini = num;
            
            // ans ko update karo
            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }

            int totalcols = arr[rindex].size();
            if(cindex+1<totalcols){
                int ele = arr[rindex][cindex+1];
                maxi = max(ele,maxi);
                Item* item = new Item(ele,rindex,cindex+1);
                pq.push(item);
            }
            // ye bhul gya tu
            else{
                // age koi element nhi hai list me
                break;
                // kyunki condition says ki sabhi list ka element hona chahiye
            }

        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};

int main(){
    
 return 0;
}




