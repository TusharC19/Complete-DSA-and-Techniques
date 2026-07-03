# include<bits/stdc++.h>
using namespace std; 

class Info{
    public:
        int data;
        int cIndex;
        int rIndex;

        Info(int x,int y,int z){
            data = x;
            cIndex = y;
            rIndex = z;
        }

};

class compare{
    public:
        bool operator()(Info* a,Info* b){
            return a->data > b->data;
        }

};

class Solution{
    public:
        vector<int>mergeKArrays(vector<vector<int>>arr, int k){
            priority_queue<Info*,vector<Info*>,compare>pq;

            
        }
};



int main(){


 return 0;
}