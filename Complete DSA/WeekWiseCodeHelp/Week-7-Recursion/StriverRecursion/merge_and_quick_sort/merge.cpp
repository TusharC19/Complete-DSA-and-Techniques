# include<bits/stdc++.h>
using namespace std; 

void merge(vector<int>&a,int low,int high,int mid){
    int left=low;
    int right=mid+1;

    vector<int>temp;

    while(left<=mid && right<=high){
        if(a[left]<a[right]) {
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(a[left]);
            left++;
    }

    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }

    // insert into original array
    for(int i=low;i<=high;i++){
        a[i]=temp[i-low];
    }
}

void mergeSort(vector<int>&a,int low,int high){
    if(low>=high) return;
    int mid=low+(high-low)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);

    // on smallest breaked parts we start to call merge
    merge(a,low,high,mid);
}



int main(){
    vector<int>a={3,1,2,4,6,5};
    mergeSort(a,0,a.size()-1);

    for(int i:a) cout<<i<<" ";

 return 0;
}