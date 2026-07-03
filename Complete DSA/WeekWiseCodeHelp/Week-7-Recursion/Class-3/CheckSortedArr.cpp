# include<bits/stdc++.h>
using namespace std; 

bool checkSortedDescending(int arr[],int i,int s){
    if(i==s-1) return true;

    if(arr[i] < arr[i+1]) return false;

    checkSortedDescending(arr,i+1,s);

}

bool checkSortedAscending(int arr[],int i,int s){
    // single element case treated as sorted
    if(i==s-1) return true;

    if(arr[i] > arr[i+1]) return false;

    bool ans = checkSortedAscending(arr,i+1,s);
    return ans;

}


int main(){
    
    int a[] = {1,2,3,4,5,6};
    int b[] = {6,5,4,3,2,1};

    int c[] = {12,34,556,78,89,100};
    if(checkSortedAscending(c,0,6)) cout<<"sorted"<<endl;
    else cout<<"not sorted"<<endl;
    


 return 0;
}