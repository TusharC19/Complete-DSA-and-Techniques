# include<bits/stdc++.h>
using namespace std; 

void countingSort(vector<int>&arr,int pos){
  
    // freq Array
    vector<int>freqArr(10,0);
    for(int i=0;i<arr.size();i++){
        int idx = ((arr[i]/pos)%10);
        freqArr[idx]++;
    }

    // cumulative Sum arr
    vector<int>cumulativeSum(10,0);
    cumulativeSum[0] = freqArr[0]; 
    for(int i=1;i<10;i++){
        cumulativeSum[i] = freqArr[i] + cumulativeSum[i-1];
    }
  
    // output Array
    vector<int>outputArr(arr.size());
    for(int i=outputArr.size()-1;i>=0;i--){
        int ele = ((arr[i]/pos)%10);
        int idx = --cumulativeSum[ele];
        outputArr[idx] = arr[i];
    }

    for(int i=0;i<arr.size();i++){
        arr[i] = outputArr[i];
    }

}

void radixSort(vector<int>&arr){

    int maxEle = INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxEle = max(maxEle,arr[i]);
    }

    // loop till max element no of digits
    for(int pos=1;(maxEle/pos)>0;pos*=10){
        countingSort(arr,pos);
    }


}







int main(){
    vector<int>a = {170,45,75,90,802,2};
    cout<<"before"<<endl;
    for(int i: a) cout<<i<<" ";

    radixSort(a);
    cout<<endl;
    cout<<"After"<<endl;
    for(int i: a) cout<<i<<" ";
    


 return 0;
}