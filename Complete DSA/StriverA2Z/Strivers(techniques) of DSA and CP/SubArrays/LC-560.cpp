# include<bits/stdc++.h>
using namespace std; 

int brute(vector<int>&a){
    int n = a.size();

    int maxsum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum  = 0;
            for(int k=i;k<=j;k++){
                sum += a[k];
            }
            maxsum = max(sum,maxsum);
        }
    }
    return maxsum;
}
// count subarrays
int bruteLenght(vector<int>&a,int m){
    int n = a.size();

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum  = 0;
            for(int k=i;k<=j;k++){
                sum += a[k];
            }
            if(sum == m) cnt++;
        }
    }
    return cnt;
}


int better(vector<int>&a,int m){
    int n = a.size();

    int cnt=0;
    for(int i=0;i<n;i++){
        int sum  = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            if(sum == m) cnt++;

        }
        
    }
    return cnt;
}

int main(){
    vector<int>a = {1,2,1,2};
    
    int b = better(a,3);


    cout<<b<<endl;


 return 0;
}



// better approach