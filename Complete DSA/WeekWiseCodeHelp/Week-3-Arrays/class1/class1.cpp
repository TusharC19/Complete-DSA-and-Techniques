# include<bits/stdc++.h>
using namespace std; 

void maxEle(int arr[],int s){
    int max = INT_MIN;
    for(int i=0;i<s;i++){
        if(arr[i]>max) max = arr[i];
    }
    cout<<max<<endl;
}
void minEle(int arr[],int s){
    int min = INT_MAX;
    for(int i=0;i<s;i++){
        if(arr[i]<min) min = arr[i];
    }
    cout<<min<<endl;
}

void extremePrint(int arr[],int s){
    int i = 0;
    int j = s-1;
    while (i<=j)
    {   
        if(i==j){
            cout<<arr[i]<<" ";
            i++;j--;
        }
        else{
        cout<<arr[i]<<" ";
        cout<<arr[j]<<" ";
        i++;j--;
        }
    }

    
}

int main(){
    // int arr[5];
    // fill(arr,arr+2,78);
    // fill(arr+2,arr+5,100);
    // for(int i:arr) cout<<i<<" ";

    int arr1[] = {10,20,30,40,50,60};
    // maxEle(arr,6);
    // minEle(arr,6);
    int arr[] = {10,20,30,40,50};

    // extremePrint(arr1,6);

    int a=3,b=7;
    a = a^b;
    b = b^a;
    a = a^b;
    cout<<a<<" "<<b<<endl;



 return 0;
}