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
        bool cmp(Item* a,Item* b){
            return a->data<b->data;
        }
};

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        
        // yha bhi same original object liya hai usko dal rhe hai na ki copy
        priority_queue<Item*,vector<Item*>,compare>pq;
        vector<int>ans;

        int totalrows = arr.size();
        int totalcols = arr[0].size();

        for(int row=0;row<totalrows;row++){
            int ele = arr[row][0];
            Item* item = new Item(ele,row,0);
            pq.push(item);
        }

        // main logic of processing the data
        while(!pq.empty()){
            Item* front = pq.top();
            pq.pop();
            int num = front->data;
            int rindex = front->rIndex;
            int cindex = front->cIndex;
            ans.push_back(num);

            // check ki age data h frontele ke , if yes then push it inside pq
            if(cindex+1<totalcols){
                int ele = arr[rindex][cindex+1];
                Item* item = new Item(ele,rindex,cindex+1);
                pq.push(item);
            }

        }

        return ans;
        
    }
};

int main(){
    Solution s;
    int k=3;
    vector<vector<int>>arr = {{1,2,3},{4,5,6},{7,8,9}};
    auto ans = s.mergeKArrays(arr,k);
    for(int i:ans) cout<<i<<" ";
    cout<<endl;
    
 return 0;
}