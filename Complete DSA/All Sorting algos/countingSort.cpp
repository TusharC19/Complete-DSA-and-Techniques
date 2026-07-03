# include<bits/stdc++.h>
using namespace std; 

void print(vector<int>&arr){
    for(int i: arr) cout<<i<<" ";
    cout<<endl;
}


void countingSort(vector<int>&arr){
    int maxiEle = INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxiEle = max(maxiEle,arr[i]);
    }
    int size = maxiEle+1;
    // count Array
    vector<int>freqArr(size);
    for(int i=0;i<arr.size();i++){
        int idx = arr[i];
        freqArr[idx]++;
    }
    // print(cntArr);

    // cumulative Sum arr
    vector<int>cumulativeSum(size);
    cumulativeSum[0] = freqArr[0]; 
    for(int i=1;i<freqArr.size();i++){
        cumulativeSum[i] = freqArr[i] + cumulativeSum[i-1];
    }

    // print(cumulativeSum);
    
    // output Array
    vector<int>outputArr(size);
    for(int i=outputArr.size()-1;i>=0;i--){
        int ele = arr[i];
        int idx = --cumulativeSum[ele];
        outputArr[idx] = ele;
    }
    // cout<<"cumulative sum"<<endl;
    // print(cumulativeSum);

    // print(outputArr);

    for(int i=0;i<arr.size();i++){
        arr[i] = outputArr[i];
    }

}


int main(){
    vector<int>a = {2,1,0,6,8,1,2,5,8};
    // for(int i: a) cout<<i<<" ";
    // cout<<endl;
    countingSort(a);
    for(int i: a) cout<<i<<" ";
    
 return 0;
}