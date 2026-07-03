# include<bits/stdc++.h>
using namespace std; 

int dectobin(int n){
    string ans = "";
    while(n>=1){
        int bit = n&1;
        ans += '0' + bit;
        n = n>>1;
    }
    int bin = stoi(ans);
    
    return bin;
    
}


int ithBit(int n,int i){
    
    // way1 
    // while(i--){
    //     n = n>>1;
    // }
    // return n&1;

    // way2- masking
    int mask = (1<<i);
    int ans = n&mask;
    return (ans) ? 1 : 0;
}

int setthbit1(int n,int i){
    int mask=(1<<i);
    int ans = (n|mask);
    return ans;
}

void setthbit0(int &n,int i){
    int mask = ~(1<<i);
    int ans = (n&mask);
    // cout<<"updated num: "<<ans<<endl;
}

void updateithbit(int n,int i,int target){
    setthbit0(n,i);
    int mask = (target<<i);
    int ans = n|mask;
    cout<<"previous number:"<<n<<endl;
    cout<<"updated number:"<<ans<<endl;

}

void clearlastithbits(int n,int i){
    int mask = (-1<<i);
    // for first ith bits -1>>i
    n = n & mask;
    cout<<n<<endl;

}

int cntSetbits(int n){
    int cnt = 0;
    while(n!=0){
        cnt++;
        n = n & (n-1);
    }
    return cnt;
}

string check2power(int n){
    int count = cntSetbits(n);
    return (count == 1) ? "yes" : "no";
}

int main(){
    // int ans = setthbit1(6,2);
    // cout<<ans<<endl;
    int n = 3;
    // clearlastithbits(15,3);
    auto ans = check2power(3);
    cout<<ans<<endl;
    
 return 0;
}